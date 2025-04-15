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

// This file contains a description of the Window class, which is a wrapper for
// working with the ncurses library.
// The class provides functions for creating windows, drawing lines, tables, and
// other interface elements.

#ifndef WINDOW_H_
#define WINDOW_H_

#include <ncurses.h>
#include <string>

#include "ui/key.h"
#include "ui/window_helpers.h"
#include "utils/point.h"
#include "window_size.h"
namespace ui {

class Window {
public:
  Window(WindowSize size, utl::PointI position);

  Window(const Window &other);

  // Deleted move constructor to prevent moving a Window object.
  Window(Window &&) = delete;

  Window &operator=(const Window &other);

  // Deleted move assignment operator to prevent moving a Window object.
  Window &operator=(Window &&) = delete;

  ~Window();

  // Method for stamping a character
  int AddCh(chtype ch) { return waddch(window_, ch); }

  // Stream insertion operators for various data types
  Window &operator<<(char ch);
  Window &operator<<(const char *str);
  Window &operator<<(const std::string &str);

  Window &operator<<(short val);
  Window &operator<<(int val);
  Window &operator<<(long val);
  Window &operator<<(long long val);

  Window &operator<<(unsigned short val);
  Window &operator<<(unsigned int val);
  Window &operator<<(unsigned long val);
  Window &operator<<(unsigned long long val);

  Window &operator<<(float val);
  Window &operator<<(double val);
  Window &operator<<(long double val);

  Window &operator<<(Window &(*fun)(Window &));

  // Overloaded statement that accepts Point to move the cursor to the specified
  // position
  Window &operator<<(utl::PointI yx);

  // Input stream operators
  Window &operator>>(int &key);
  Window &operator>>(Key &key);

  // Metods for reading a key from the input stream.
  int Getch();
  Key GetKey();

  // Methods for cleaning the window
  int Clear() { return wclear(window_); }
  int Werase() { return werase(window_); }

  int Resize(WindowSize size);
  // Method to refresh the window
  void Refresh() { wrefresh(window_); }

  // Methods for drawing a frame around a window.
  int Box() { return box(window_, 0, 0); }
  int Box(chtype verch, chtype horch) { return box(window_, verch, horch); }

  void HLine(chtype ch, int n) { whline(window_, ch, n); }
  void HLine(int y, int x, chtype ch, int n) { mvwhline(window_, y, x, ch, n); }

  void VLine(chtype ch, int n) { wvline(window_, ch, n); }
  void VLine(int y, int x, chtype ch, int n) { mvwvline(window_, y, x, ch, n); }

  // Methods for moving the cursor
  int Move(int y, int x) { return wmove(window_, y, x); }
  int Move(utl::PointI yx) { return wmove(window_, yx.y, yx.x); }

  // Methods for moving a window
  int MoveWin(int y, int x) { return mvwin(window_, y, x); }
  int MoveWin(utl::PointI yx) { return mvwin(window_, yx.y, yx.x); }

  // Method for enabling the attribute
  int AttrOn(int attrs) { return wattron(window_, attrs); }

  // Method for disabling an attribute.
  int AttrOff(int attrs) { return wattroff(window_, attrs); }

  // Method for set the attribute
  int AttrSet(int attrs) { return wattrset(window_, attrs); }

  // Method for setting a background for a window.
  int BkGd(chtype ch) { return wbkgd(window_, ch); }

  // Method for enabling the processing of special keys (arrows, F1, etc.).
  int Keypad(bool bf) { return keypad(window_, bf); }

  // Enables or disables non-blocking input for the window.
  int NoDelate(bool bf) { return nodelay(window_, bf); }

  // Enables or disables window scrolling.
  int Scrollok(bool bf) { return scrollok(window_, bf); }

  // Methods for getting the window size
  int GetMaxY() { return getmaxy(window_); }
  int GetMaxX() { return getmaxx(window_); }
  ui::WindowSize GetMaxYX();

  // Method for getting window cursor positions
  utl::PointI GetYX();

private:
  WINDOW *window_;
  WindowSize size_;
  utl::Point position_;

  static constexpr short kMinSize_ = 1;

  // Creates a new window
  void NewWin();
};

} // namespace ui

#endif // !WINDOW_H_
