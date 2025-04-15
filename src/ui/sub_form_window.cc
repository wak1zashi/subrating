// This file is part of subrating.
//
// wcuses is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// wcuses is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with wcuses.  If not, see <http://www.gnu.org/licenses/>.

#include "ui/sub_form_window.h"

#include <algorithm>
#include <limits>
#include <ncurses.h>
#include <string>
#include <vector>

#include "models/subscriber.h"
#include "services/convert.h"
#include "services/subscriber_manager.h"
#include "ui/key.h"
#include "ui/layout_manager.h"
#include "ui/menus_enumerations.h"
#include "ui/window.h"
#include "ui/window_helpers.h"
#include "utils/point.h"

ui::SubFormWindow::SubFormWindow()
    : sub_form_win_(LayoutManager::GetMainWimSize(),
                    LayoutManager::GetMainWinPos()) {}

void ui::SubFormWindow::AddSub(service::SubscriberManager &sub_manager) {
  flag_add_mode = true;
  Restore();

  UpdateSubLevel();
  for (;;) {

    RenderWindow();
    sub_form_win_.Refresh();
    if (HandleKeyPress()) {
      sub_manager.AddSub(CreateSubData());
      return;
    }
  }
}

void ui::SubFormWindow::EditSub(const sub::Subscriber &sub,
                                service::SubscriberManager &sub_manager) {
  flag_add_mode = false;

  Restore();
  FillField(sub);

  UpdateSubLevel();
  for (;;) {

    RenderWindow();
    sub_form_win_.Refresh();
    if (HandleKeyPress()) {
      sub_manager.EditSub(sub.GetId(), CreateSubData());
      return;
    }
  }
}

void ui::SubFormWindow::Clear() {
  sub_form_win_.Clear();
  sub_form_win_.Box();
}

void ui::SubFormWindow::RenderWindow() {

  sub_form_win_.Move(LayoutManager::GetWinModePos());
  if (flag_add_mode) {
    sub_form_win_ << " Add ";
  } else {
    sub_form_win_ << " Edit ";
  }

  const utl::PointI kCenterPos((sub_form_win_.GetMaxY() - 11) / 2,
                               (sub_form_win_.GetMaxX() - 38) / 2);

  int current_index = static_cast<int>(current_menu_items_);

  for (int i = 0; i < menu_items_.size(); ++i) {
    sub_form_win_.Move(kCenterPos.y + i * 2, kCenterPos.x);

    bool is_selected = (i == current_index);
    if (is_selected) {
      sub_form_win_.AttrOn(A_REVERSE);
    }

    sub_form_win_ << menu_items_[i].label;

    int padding =
        std::max(0, 16 - static_cast<int>(menu_items_[i].label.size()));
    sub_form_win_ << std::string(padding, ' ') << ":";

    if (is_selected) {
      sub_form_win_.AttrOff(A_REVERSE);
    }

    sub_form_win_ << " " << menu_items_[i].value;
  }
}

bool ui::SubFormWindow::HandleKeyPress() {

  ui::Key key;
  sub_form_win_ >> key;

  switch (key) {
  case ui::Key::kEnter:
    for (const auto &iter : menu_items_) {
      if (iter.value.empty()) {
        return false;
      }
    }
    return true;
    break;

  case ui::Key::kLowerJ:
  case ui::Key::kUpperJ:
    ChangeMenuItemDown(current_menu_items_, SubFormMenuItem::kNickName,
                       SubFormMenuItem::kTimeSpent);
    break;

  case ui::Key::kLowerK:
  case ui::Key::kUpperK:
    ChangeMenuItemUp(current_menu_items_, SubFormMenuItem::kNickName,
                     SubFormMenuItem::kTimeSpent);
    break;

  case ui::Key::kLowerH:
  case ui::Key::kUpperH:
    HandleHPress();
    break;

  case ui::Key::kLowerL:
  case ui::Key::kUpperL:
    HandleLPress();
    break;

  default:
    // no code
    break;
  }

  return false;
}

void ui::SubFormWindow::HandleHPress() {
  switch (current_menu_items_) {
  case SubFormMenuItem::kSubLevel:
    ChangeMenuItemUp(sub_level_, sub::SubLevel::kStandard, sub::SubLevel::kVIP);
    UpdateSubLevel();
    break;

  default:
    // no code
    break;
  }
}

void ui::SubFormWindow::HandleLPress() {
  switch (current_menu_items_) {
  case SubFormMenuItem::kNickName:
    CaptureNameInput(menu_items_[static_cast<int>(current_menu_items_)]);
    break;

  case ui::SubFormMenuItem::kCommentCount:
  case ui::SubFormMenuItem::kLikesCount:
  case ui::SubFormMenuItem::kViewsCount:
  case ui::SubFormMenuItem::kTimeSpent:
    CaptureTypedDigits(menu_items_[static_cast<int>(current_menu_items_)]);
    break;

  case SubFormMenuItem::kSubLevel:
    ChangeMenuItemDown(sub_level_, sub::SubLevel::kStandard,
                       sub::SubLevel::kVIP);
    UpdateSubLevel();
    break;

  default:
    // no code
    break;
  }
}

void ui::SubFormWindow::CaptureNameInput(Field &field) {
  const size_t max_length = service::SubscriberManager::GetMaxLengthNickName();
  size_t index = (field.value.size() > 1) ? field.value.size() : 0;

  for (;;) {
    ui::Key key;
    sub_form_win_ >> key;

    if (key == Key::kEscape) {
      return;
    }

    if (index > 0 && key == Key::kBackspace) {
      Clear();
      field.value.pop_back();
      --index;
    }

    if (index < max_length && ((key >= Key::kUpperA && key <= Key::kUpperZ) ||
                               (key >= Key::kLowerA && key <= Key::kLowerZ) ||
                               (key >= Key::kDigit0 && key <= Key::kDigit9))) {
      if (index < field.value.size())
        field.value[index] = static_cast<char>(key);
      else
        field.value.push_back(static_cast<char>(key));
      ++index;
    }

    RenderWindow();
    sub_form_win_.Refresh();
  }
}

void ui::SubFormWindow::CaptureTypedDigits(Field &field) {
  constexpr size_t kMaxDigits = std::numeric_limits<unsigned int>::digits10;
  size_t index = (field.value.size() > 1) ? field.value.size() : 0;

  auto normalize_value = [](std::string &value) {
    if (value.empty()) {
      value = "0";
      return;
    }

    const size_t first_non_zero = value.find_first_not_of('0');
    value = (first_non_zero != std::string::npos) ? value.substr(first_non_zero)
                                                  : "0";

    if (std::stoull(value) > std::numeric_limits<unsigned int>::max()) {
      value = std::to_string(std::numeric_limits<unsigned int>::max());
    }
  };

  for (;;) {
    ui::Key key;
    sub_form_win_ >> key;

    if (key == Key::kEscape) {
      normalize_value(field.value);
      Clear();
      return;
    }

    if (key == Key::kBackspace && index > 0) {
      Clear();
      field.value.pop_back();
      --index;
    }

    if (key >= Key::kDigit0 && key <= Key::kDigit9 && index <= kMaxDigits) {
      if (index < field.value.size()) {
        field.value[index] = static_cast<char>(key);
      } else {
        field.value.push_back(static_cast<char>(key));
      }
      ++index;
    }

    RenderWindow();
    sub_form_win_.Refresh();
  }
}

void ui::SubFormWindow::UpdateSubLevel() {
  std::string &value =
      menu_items_[static_cast<int>(SubFormMenuItem::kSubLevel)].value;

  value = service::SubLevelToStr(sub_level_);

  sub_form_win_.Clear();
  sub_form_win_.Box();
}

service::SubData ui::SubFormWindow::CreateSubData() {
  service::SubData sub_data;
  sub_data.nick_name =
      menu_items_[static_cast<int>(SubFormMenuItem::kNickName)].value;

  sub_data.sub_level = sub_level_;

  unsigned int temp;

  temp = std::stoul(
      menu_items_[static_cast<int>(SubFormMenuItem::kCommentCount)].value);
  sub_data.activity.SetСommentCount(temp);

  temp = std::stoul(
      menu_items_[static_cast<int>(SubFormMenuItem::kLikesCount)].value);
  sub_data.activity.SetLikesCount(temp);

  temp = std::stoul(
      menu_items_[static_cast<int>(SubFormMenuItem::kViewsCount)].value);
  sub_data.activity.SetViewsCount(temp);

  temp = std::stoul(
      menu_items_[static_cast<int>(SubFormMenuItem::kTimeSpent)].value);
  sub_data.activity.SetTimeSpent(temp);

  return sub_data;
}

void ui::SubFormWindow::FillField(const sub::Subscriber &sub) {

  sub_level_ = sub.GetSubLevel();

  std::vector<Field> menu_items = {
      {"Nick name", sub.GetNickName()},
      {"Sub level", service::SubLevelToStr(sub_level_)},
      {"Comment count", std::to_string(sub.GetActivity().GetСommentCount())},
      {"Likes count", std::to_string(sub.GetActivity().GetLikesCount())},
      {"Views count", std::to_string(sub.GetActivity().GetViewsCount())},
      {"Time spent (s)", std::to_string(sub.GetActivity().GetTimeSpent())}};

  menu_items_ = std::move(menu_items);
}

void ui::SubFormWindow::Restore() {
  std::vector<Field> menu_items = {
      {"Nick name", ""},    {"Sub level", ""},    {"Comment count", "0"},
      {"Likes count", "0"}, {"Views count", "0"}, {"Time spent (s)", "0"}};

  menu_items_ = std::move(menu_items);

  sub_level_ = sub::SubLevel::kStandard;

  current_menu_items_ = SubFormMenuItem::kNickName;

  Clear();
}
