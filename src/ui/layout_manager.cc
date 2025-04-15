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

#include "ui/layout_manager.h"
#include "utils/point.h"

#include <ncurses.h>

ui::WindowSize ui::LayoutManager::terminal_size_ = {0, 0};

ui::WindowSize ui::LayoutManager::header_win_size_{0, 0};
const utl::PointI ui::LayoutManager::header_win_pos_(0, 0);

ui::WindowSize ui::LayoutManager::main_win_size_{0, 0};
utl::PointI ui::LayoutManager::main_win_pos_(0, 0);
utl::PointI ui::LayoutManager::win_mode_pos_(0, 0);

ui::WindowSize ui::LayoutManager::cmd_win_size_{0, 0};
utl::PointI ui::LayoutManager::cmd_win_pos_(0, 0);

void ui::LayoutManager::Init() {
  getmaxyx(stdscr, terminal_size_.height, terminal_size_.width);

  header_win_size_ = {3, terminal_size_.width};

  cmd_win_size_ = {3, terminal_size_.width};

  int height =
      terminal_size_.height - header_win_size_.height - cmd_win_size_.height;
  main_win_size_ = {height, terminal_size_.width};

  main_win_pos_ = {header_win_size_.height, 0};

  win_mode_pos_ = {0, 4};

  cmd_win_pos_ = {header_win_size_.height + main_win_size_.height, 0};
}
