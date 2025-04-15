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

#include "ui/view_window.h"

#include <functional>

#include "models/subscriber.h"
#include "services/convert.h"
#include "ui/layout_manager.h"
#include "ui/window_helpers.h"
#include "utils/point.h"
#include <ncurses.h>

ui::ViewWindow::ViewWindow()
    : view_win(LayoutManager::GetMainWimSize(), LayoutManager::GetMainWinPos()),
      kHeaderPos(1, (view_win.GetMaxX() - kStringLength) / 2),
      table_header{{"ID", 11},    {"Name", 22},       {"Rating", 11},
                   {"Level", 11}, {"Likes", 11},      {"Comments", 11},
                   {"Views", 11}, {"Time Spent", 11}, {"Data", 25}} {
  max_sub_on_screen = (view_win.GetMaxY() - 4) / 2;
}

void ui::ViewWindow::RenderSubs(
    int curenSub, int start_index,
    const std::vector<const sub::Subscriber *> &sub) {
  view_win.Box();
  RenderHeader();

  for (int sub_on_screen = 0, i = start_index;
       i < sub.size() && sub_on_screen < max_sub_on_screen;
       ++i, ++sub_on_screen) {

    if (i == curenSub) {
      RenderSub(true, sub_on_screen + 1, *sub[i]);
    } else {
      RenderSub(false, sub_on_screen + 1, *sub[i]);
    }
  }

  view_win.Refresh();
}

void ui::ViewWindow::Clear() {
  view_win.Clear();
  view_win.Box();
}

void ui::ViewWindow::RenderHeader() {
  utl::PointI pos(kHeaderPos);

  for (int i = 0; i < table_header.size(); ++i) {

    view_win.Move(pos.y, pos.x);

    view_win << AcsVline;

    view_win << table_header[i].title;

    pos.x += table_header[i].column_widths;

    if (i == table_header.size() - 1) {
      view_win.Move(pos.y, pos.x);
      view_win << AcsVline;

      view_win.Move(kHeaderPos.y + 1, kHeaderPos.x);
      view_win.HLine(ACS_HLINE, kStringLength);
    }
  }
}

void ui::ViewWindow::RenderSub(bool backlight, int move_step,
                               const sub::Subscriber &sub) {

  std::vector<std::function<std::string()>> content_printers = {
      [&]() { return std::to_string(sub.GetId()); },
      [&]() { return sub.GetNickName(); },
      [&]() { return std::to_string(sub.GetRating()); },
      [&]() { return service::SubLevelToStr(sub.GetSubLevel()); },
      [&]() { return std::to_string(sub.GetActivity().GetLikesCount()); },
      [&]() { return std::to_string(sub.GetActivity().GetСommentCount()); },
      [&]() { return std::to_string(sub.GetActivity().GetViewsCount()); },
      [&]() { return std::to_string(sub.GetActivity().GetTimeSpent()); },
      [&]() { return sub.GetStrTime(); }};

  utl::PointI pos(kHeaderPos.y + 2 * move_step, kHeaderPos.x);

  for (int i = 0; i < content_printers.size(); ++i) {

    view_win.Move(pos.y, pos.x);

    if (backlight) {
      view_win.AttrOn(A_REVERSE);
    }

    view_win << AcsVline << content_printers[i]();

    if (i < table_header.size()) {
      pos.x += table_header[i].column_widths;
    }

    if (i == table_header.size() - 1) {
      view_win.Move(pos.y, pos.x);
      view_win << AcsVline;

      if (backlight) {
        view_win.AttrOff(A_REVERSE);
      }

      view_win.Move(pos.y + 1, kHeaderPos.x);
      view_win.HLine(ACS_HLINE, kStringLength);
    }
  }
}
