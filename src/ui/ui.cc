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

#include "ui/ui.h"

#include <ncurses.h>

#include "models/subscriber_enums.h"
#include "services/convert.h"
#include "services/subscriber_manager.h"
#include "ui/key.h"
#include "ui/layout_manager.h"
#include "ui/menus_enumerations.h"

ui::UI::UI()
    : header_("substats"),
      cmd_(LayoutManager::GetCmdWinSize(), LayoutManager::GetCmdWinPos()) {
  logo_.Render();
  sub::Activity acti;

  sub_manager_.Load();
  MainLoop();
}

void ui::UI::MainLoop() {

  header_.Refresh();
  cmd_.Box();
  cmd_.Refresh();
  is_run_ = true;

  int start_index = 0;
  int curen_sub = 0;

  for (; is_run_;) {
    view_window_.RenderSubs(curen_sub, start_index, sub_manager_.GetSubsList());

    Key key;
    input_mg >> key;

    if (key == Key::kLowerJ) {
      if (curen_sub == start_index + view_window_.GetMaxSubOnScreen() - 1 &&
          start_index < sub_manager_.GetSubsList().size() -
                            view_window_.GetMaxSubOnScreen()) {
        ++start_index;
        view_window_.Clear();
      }

      if (curen_sub < start_index + view_window_.GetMaxSubOnScreen() - 1 &&
          curen_sub < sub_manager_.GetSubsList().size() - 1) {
        ++curen_sub;
      }
    }

    if (key == Key::kLowerK) {
      if (start_index == curen_sub && start_index > 0) {
        --start_index;
        view_window_.Clear();
      }

      if (curen_sub > start_index && curen_sub > 0) {
        --curen_sub;
      }
    }

    if (key == Key::kLowerA) {
      sub_form_.AddSub(sub_manager_);
      view_window_.Clear();
    }

    if (key == Key::kLowerE && !sub_manager_.GetSubsList().empty()) {
      view_window_.Clear();
      sub_form_.EditSub(*sub_manager_.GetSubsList()[curen_sub], sub_manager_);
    }

    if (key == Key::kLowerD && !sub_manager_.GetSubsList().empty()) {

      if (!ConfirmationDeletionSub(sub_manager_.GetSubsList()[curen_sub])) {
        continue;
      }

      view_window_.Clear();
      sub_manager_.DelSub(sub_manager_.GetSubsList()[curen_sub]->GetId());

      if (start_index == curen_sub && start_index > 0) {
        --start_index;
        view_window_.Clear();
      }

      if (curen_sub > start_index && curen_sub > 0) {
        --curen_sub;
      }

      if (start_index > sub_manager_.GetSubsList().size() -
                            view_window_.GetMaxSubOnScreen()) {
        --start_index;
      }
    }

    if (key == Key::kLowerF) {
      SelectingFilter();
      view_window_.Clear();
    }

    if (key == Key::kLowerS) {
      SelectingSortT();
      view_window_.Clear();
    }

    if (key == Key::kLowerQ) {
      sub_manager_.Sava();
      is_run_ = false;
      continue;
    }
  }
}
bool ui::UI::ConfirmationDeletionSub(const sub::Subscriber *sub) {
  cmd_.Move(1, 1);
  cmd_ << "Remove subscription ID " << sub->GetId() << "? (y/N):";
  cmd_.Refresh();

  for (;;) {
    Key key;
    cmd_ >> key;

    switch (key) {
    case Key::kEscape:
      ClearCmd();
      return false;

    case Key::kLowerY:
    case Key::kUpperY:
      ClearCmd();
      return true;

    case Key::kLowerN:
    case Key::kUpperN:
      ClearCmd();
      return false;

    default:
      // no code
      break;
    }
  }
}

void ui::UI::SelectingFilter() {
  sub::Filter new_filter = sub_manager_.GetFilter();

  for (;;) {

    ClearCmd();
    cmd_.Move(1, 1);
    cmd_ << "<Filter>: " << service::FilterToStr(new_filter);
    cmd_.Refresh();

    Key key;
    cmd_ >> key;

    switch (key) {
    case Key::kEscape:
      ClearCmd();
      return;

    case Key::kEnter:
      if (new_filter != sub_manager_.GetFilter()) {
        sub_manager_.SetFilter(new_filter);
      }

      ClearCmd();
      return;

    case Key::kLowerH:
    case Key::kUpperH:
      ChangeMenuItemUp(new_filter, sub::Filter::kAll, sub::Filter::kVIP);
      break;

    case Key::kLowerL:
    case Key::kUpperL:
      ChangeMenuItemDown(new_filter, sub::Filter::kAll, sub::Filter::kVIP);
      break;

    default:
      // no code
      break;
    }
  }
}

void ui::UI::SelectingSortT() {
  sub::SortT new_sort_t = sub_manager_.GetSortT();
  bool new_growth = sub_manager_.GetGrowth();

  for (;;) {

    ClearCmd();
    cmd_.Move(1, 1);
    cmd_ << "<SortT>: " << service::SortTToStr(new_sort_t)
         << (new_growth ? "" : "");
    cmd_.Refresh();

    Key key;
    cmd_ >> key;

    switch (key) {
    case Key::kEscape:
      ClearCmd();
      return;

    case Key::kEnter:
      if (new_sort_t != sub_manager_.GetSortT()) {
        sub_manager_.SetSort(new_sort_t);
      }

      if (new_growth != sub_manager_.GetGrowth()) {
        sub_manager_.SetGrowth(new_growth);
      }

      ClearCmd();
      return;

    case Key::kLowerH:
    case Key::kUpperH:
      ChangeMenuItemUp(new_sort_t, sub::SortT::ID, sub::SortT::kRating);
      break;

    case Key::kLowerL:
    case Key::kUpperL:
      ChangeMenuItemDown(new_sort_t, sub::SortT::ID, sub::SortT::kRating);
      break;

    case Key::kLowerK:
    case Key::kUpperK:
      new_growth = new_growth ? false : true;
      break;

    case Key::kLowerJ:
    case Key::kUpperJ:
      new_growth = new_growth ? false : true;
      break;

    default:
      // no code
      break;
    }
  }
}

void ui::UI::ClearCmd() {
  cmd_.Clear();
  cmd_.Box();
  cmd_.Refresh();
}
