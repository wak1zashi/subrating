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

#ifndef VIEW_WINDOW_H_
#define VIEW_WINDOW_H_

#include "vector"

#include "models/subscriber.h"
#include "window.h"
#include <string>

namespace ui {

struct TableHeader {
  const std::string title;
  const int column_widths;
};

class ViewWindow {
public:
  ViewWindow();

  void RenderSubs(int curenSub, int start_index,
                  const std::vector<const sub::Subscriber *> &sub);

  void Clear();

  int GetMaxSubOnScreen() { return max_sub_on_screen; }

private:
  static constexpr int kStringLength = 125;

  int max_sub_on_screen;

  Window view_win;

  std::vector<TableHeader> table_header;

  const utl::PointI kHeaderPos;

  void RenderHeader();
  void RenderSub(bool backlight, int move_step, const sub::Subscriber &sub);
};

} // namespace ui

#endif // !VIEW_WINDOW_H_
