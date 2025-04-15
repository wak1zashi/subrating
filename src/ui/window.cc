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

#include "ui/window.h"

#include <algorithm>
#include <ncurses.h>

#include "ui/key.h"
#include "ui/window_helpers.h"
#include "ui/window_size.h"
#include "utils/point.h"

ui::Window::Window(WindowSize size, utl::PointI position)
    : size_{std::max<short>(size.height, 1), std::max<short>(size.width, 1)},
      position_(std::max(position.y, 0), std::max(position.x, 0)) {

  this->NewWin();
}

ui::Window::Window(const Window &other)
    : size_(other.size_), position_(other.position_) {

  this->NewWin();
}

ui::Window &ui::Window::operator=(const Window &other) {
  if (this == &other) {
    return *this;
  }

  this->size_ = other.size_;
  this->position_ = other.position_;

  delwin(this->window_);

  this->NewWin();
  return *this;
}

ui::Window::~Window() {
  delwin(window_);
  window_ = nullptr;
}

ui::Window &ui::Window::operator<<(char ch) {
  waddch(window_, ch);
  return *this;
}

ui::Window &ui::Window::operator<<(const char *str) {
  waddstr(window_, str);
  return *this;
}

ui::Window &ui::Window::operator<<(const std::string &str) {
  waddstr(window_, str.c_str());
  return *this;
}

ui::Window &ui::Window::operator<<(short val) {
  wprintw(window_, "%d", val);
  return *this;
}

ui::Window &ui::Window::operator<<(int val) {
  wprintw(window_, "%d", val);
  return *this;
}

ui::Window &ui::Window::operator<<(long val) {
  wprintw(window_, "%ld", val);
  return *this;
}

ui::Window &ui::Window::operator<<(long long val) {
  wprintw(window_, "%lld", val);
  return *this;
}

ui::Window &ui::Window::operator<<(unsigned short val) {
  wprintw(window_, "%u", val);
  return *this;
}

ui::Window &ui::Window::operator<<(unsigned int val) {
  wprintw(window_, "%u", val);
  return *this;
}

ui::Window &ui::Window::operator<<(unsigned long val) {
  wprintw(window_, "%lu", val);
  return *this;
}
ui::Window &ui::Window::operator<<(unsigned long long val) {
  wprintw(window_, "%llu", val);
  return *this;
}

ui::Window &ui::Window::operator<<(float val) {
  wprintw(window_, "%f", val);
  return *this;
}

ui::Window &ui::Window::operator<<(double val) {
  wprintw(window_, "%f", val);
  return *this;
}

ui::Window &ui::Window::operator<<(long double val) {
  wprintw(window_, "%.Lf", val);
  return *this;
}

ui::Window &ui::Window::operator<<(Window &(*fun)(Window &)) {
  return fun(*this);
}

ui::Window &ui::Window::operator<<(utl::PointI yx) {
  wmove(window_, yx.y, yx.x);
  return *this;
}

ui::Window &ui::Window::operator>>(int &key) {
  key = wgetch(window_);
  return *this;
}

ui::Window &ui::Window::operator>>(Key &key) {
  key = static_cast<Key>(wgetch(window_));
  return *this;
}

int ui::Window::Getch() {
  int key;
  *this >> key;

  return key;
}

ui::Key ui::Window::GetKey() {
  Key key;
  *this >> key;

  return key;
}

int ui::Window::Resize(WindowSize size) {
  return wresize(window_, size.height, size.width);
}

ui::WindowSize ui::Window::GetMaxYX() {
  ui::WindowSize yx(0, 0);

  getmaxyx(window_, yx.height, yx.width);

  return yx;
}

utl::PointI ui::Window::GetYX() {
  utl::PointI yx(0, 0);

  getyx(window_, yx.y, yx.x);
  return yx;
}

void ui::Window::NewWin() {
  if (!window_) {
    delwin(this->window_);
  }

  this->window_ = newwin(this->size_.height, this->size_.width,
                         this->position_.y, this->position_.x);
}
