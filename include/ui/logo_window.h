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

#ifndef LOGO_WINDOW_H_
#define LOGO_WINDOW_H_

#include <ncurses.h>

#include "utils/file_utils.h"
#include "window.h"

namespace ui {

class LogoWindow {
public:
  LogoWindow();

  void Render();

  void Resize();

  bool GetIsError() { return error_; }

private:
  Window logo_win_;
  bool error_;
  utl::FileData logo_data_;
};

} // namespace ui

#endif // !LOGO_WINDOW_H_
