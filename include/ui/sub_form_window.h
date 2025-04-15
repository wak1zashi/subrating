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

#ifndef SUB_FORM_WINDOW_H_
#define SUB_FORM_WINDOW_H_

#include <ncurses.h>
#include <string>
#include <vector>

#include "menus_enumerations.h"
#include "models/subscriber.h"
#include "services/subscriber_manager.h"
#include "window.h"

namespace ui {

struct Field {
  const std::string label;
  std::string value;
};

class SubFormWindow {
public:
  SubFormWindow();

  void AddSub(service::SubscriberManager &sub_manager);
  void EditSub(const sub::Subscriber &sub,
               service::SubscriberManager &sub_manager);

private:
  Window sub_form_win_;

  SubFormMenuItem current_menu_items_ = SubFormMenuItem::kNickName;

  sub::SubLevel sub_level_ = sub::SubLevel::kStandard;

  std::vector<Field> menu_items_ = {
      {"Nick name", ""},    {"Sub level", ""},    {"Comment count", "0"},
      {"Likes count", "0"}, {"Views count", "0"}, {"Time spent (s)", "0"}};

  bool flag_add_mode = true;

  void Clear();

  void RenderWindow();

  bool HandleKeyPress();

  void HandleHPress();
  void HandleLPress();

  void CaptureNameInput(Field &field);
  void CaptureTypedDigits(Field &field);

  void UpdateSubLevel();

  service::SubData CreateSubData();
  void FillField(const sub::Subscriber &sub);

  void Restore();
};

} // namespace ui

#endif // !SUB_FORM_WINDOW_H_
