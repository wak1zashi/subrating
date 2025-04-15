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

#ifndef HEADER_WINDOW_H_
#define HEADER_WINDOW_H_

#include <ncurses.h>
#include <string>

#include "window.h"
#include "window_size.h"

namespace ui {

class HeaderWindow {
public:
  HeaderWindow(const std::string &title);

  void Refresh();

  void Resize();

  bool SetTitle(const std::string &title);

  const std::string &GetTitle() const { return title_; }

private:
  Window header_win_;
  std::string title_;
};

} // namespace ui

#endif // !HEADER_WINDOW_H_
