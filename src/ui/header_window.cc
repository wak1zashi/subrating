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

#include "ui/header_window.h"

#include <string>

#include "ui/layout_manager.h"
#include "ui/window_helpers.h"
#include "ui/window_size.h"

ui::HeaderWindow::HeaderWindow(const std::string &title)
    : header_win_(ui::LayoutManager::GetHeaderWinSize(),
                  ui::LayoutManager::GetHeaderWinPos()),
      title_("title") {
  SetTitle(title);
}

bool ui::HeaderWindow::SetTitle(const std::string &title) {
  if (title.size() > header_win_.GetMaxX() - 2) {
    return false;
  }

  this->title_ = title;

  return true;
}

void ui::HeaderWindow::Refresh() {
  header_win_.Clear();
  header_win_.Box();
  header_win_.Move(header_win_.GetMaxY() / 2,
                   (header_win_.GetMaxX() - title_.size()) / 2);
  header_win_ << title_;
  header_win_.Refresh();
}

void ui::HeaderWindow::Resize() {
  header_win_.Resize(ui::LayoutManager::GetHeaderWinSize());
}
