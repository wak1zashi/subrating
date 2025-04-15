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

#ifndef UI_H_
#define UI_H_

#include "header_window.h"
#include "input_manager.h"
#include "logo_window.h"
#include "sub_form_window.h"
#include "view_window.h"
#include "window.h"

namespace ui {

class UI {
public:
  UI();

  void MainLoop();

private:
  bool is_run_ = false;

  sub::SortT sort_t_ = sub::SortT::ID;

  InputManager input_mg;
  service::SubscriberManager sub_manager_;
  ViewWindow view_window_;
  HeaderWindow header_;
  SubFormWindow sub_form_;
  Window cmd_;
  LogoWindow logo_;

  bool ConfirmationDeletionSub(const sub::Subscriber *sub);
  void SelectingFilter();
  void SelectingSortT();

  void ClearCmd();
};

} // namespace ui

#endif // !UI_H_
