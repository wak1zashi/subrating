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

#ifndef LAYOUT_MANAGER_H_
#define LAYOUT_MANAGER_H_

#include <ncurses.h>

#include "utils/point.h"
#include "window_size.h"

namespace ui {

class LayoutManager {
public:
  LayoutManager() = delete;

  static void Init();

  static WindowSize GetTerminalSize() { return terminal_size_; }
  static WindowSize GetHeaderWinSize() { return header_win_size_; }
  static WindowSize GetMainWimSize() { return main_win_size_; }
  static WindowSize GetCmdWinSize() { return cmd_win_size_; }

  static const utl::PointI GetHeaderWinPos() { return header_win_pos_; }
  static const utl::PointI GetWinModePos() { return win_mode_pos_; }
  static const utl::PointI GetMainWinPos() { return main_win_pos_; }
  static const utl::PointI GetCmdWinPos() { return cmd_win_pos_; }

private:
  static WindowSize terminal_size_;

  static WindowSize header_win_size_;
  static const utl::PointI header_win_pos_;

  static WindowSize main_win_size_;
  static utl::PointI main_win_pos_;
  static utl::PointI win_mode_pos_;

  static WindowSize cmd_win_size_;
  static utl::PointI cmd_win_pos_;
};

} // namespace ui
#endif // !LAYOUT_MANAGER_H_
