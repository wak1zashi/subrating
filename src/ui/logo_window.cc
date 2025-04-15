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

#include "ui/logo_window.h"

#include <ncurses.h>
#include <sstream>

#include "ui/layout_manager.h"
#include "ui/window.h"
#include "utils/file_utils.h"
#include "utils/point.h"

ui::LogoWindow::LogoWindow()
    : logo_win_(ui::LayoutManager::GetTerminalSize(), {0, 0}), error_(false) {
  logo_data_.file_name = "assets/logo.txt";

  logo_win_.NoDelate(true);

  error_ = utl::Load(logo_data_);
}

void ui::LogoWindow::Render() {
  if (!error_) {
    return;
  }

  utl::Point curs(0, (logo_win_.GetMaxX() - 74) / 2);
  std::istringstream iss(logo_data_.content);
  std::string line;

  for (; std::getline(iss, line); ++curs.y) {
    logo_win_.Move(curs.y, curs.x);
    logo_win_ << line;
    logo_win_.Refresh();
    napms(240);

    int key = logo_win_.Getch();
    if (key != ERR) {
      break;
    }
  }
}
