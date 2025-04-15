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

#ifndef INPUT_MANAGER_H_
#define INPUT_MANAGER_H_

#include <ncurses.h>

#include "key.h"

namespace ui {

class InputManager {
public:
  // Input stream operators
  InputManager &operator>>(int &key);
  InputManager &operator>>(Key &key);

  // Metods for reading a key from the input stream.
  int Getch();
  Key GetKey();
};

} // namespace ui

#endif // !INPUT_MANAGER_H_
