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

#include "ui/input_manager.h"
#include "ui/key.h"

ui::InputManager &ui::InputManager::operator>>(int &key) {
  key = getch();
  return *this;
}

ui::InputManager &ui::InputManager::operator>>(Key &key) {
  key = static_cast<Key>(getch());
  return *this;
}

int ui::InputManager::Getch() {
  int key;
  *this >> key;

  return key;
}

ui::Key ui::InputManager::GetKey() {
  Key key;
  *this >> key;

  return key;
}
