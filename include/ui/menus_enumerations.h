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

#ifndef MENUS_ENUMERATIONS_H_
#define MENUS_ENUMERATIONS_H_

namespace ui {

enum class SubFormMenuItem {
  kNickName,
  kSubLevel,
  kCommentCount,
  kLikesCount,
  kViewsCount,
  kTimeSpent
};

enum class Mode {
  kView,
  kAdd,
  kEdit,
};

template <typename MenuItemType>
void ChangeMenuItemUp(MenuItemType &item, MenuItemType first_item,
                      MenuItemType last_item) {
  item = (item == first_item) ? last_item
                              : MenuItemType(static_cast<int>(item) - 1);
}

template <typename MenuItemType>
void ChangeMenuItemDown(MenuItemType &item, MenuItemType first_item,
                        MenuItemType last_item) {
  item = (item == last_item) ? first_item
                             : MenuItemType(static_cast<int>(item) + 1);
}

} // namespace ui

#endif // !MENUS_ENUMERATIONS_H_
#define MENUS_ENUMERATIONS_H_
