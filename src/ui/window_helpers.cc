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

#include "ui/window_helpers.h"

#include <ncurses.h>

#include "ui/window.h"
#include "ui/window_size.h"
#include "utils/point.h"

ui::Window &ui::Endl(Window &win) { return win << '\n'; }
utl::PointI ui::Move(int y, int x) { return utl::PointI(y, x); }

ui::Window &ui::AcsHline(Window &win) {
  win.AddCh(ACS_HLINE);
  return win;
}

ui::Window &ui::AcsBtee(Window &win) {
  win.AddCh(ACS_BTEE);
  return win;
}

ui::Window &ui::AcsLlcorner(Window &win) {
  win.AddCh(ACS_LLCORNER);
  return win;
}

ui::Window &ui::AcsLrcorner(Window &win) {
  win.AddCh(ACS_LRCORNER);
  return win;
}

ui::Window &ui::AcsLtee(Window &win) {
  win.AddCh(ACS_LTEE);
  return win;
}

ui::Window &ui::AcsPlus(Window &win) {
  win.AddCh(ACS_PLUS);
  return win;
}

ui::Window &ui::AcsRtee(Window &win) {
  win.AddCh(ACS_RTEE);
  return win;
}

ui::Window &ui::AcsTtee(Window &win) {
  win.AddCh(ACS_TTEE);
  return win;
}

ui::Window &ui::AcsUlcorner(Window &win) {
  win.AddCh(ACS_ULCORNER);
  return win;
}

ui::Window &ui::AcsUrcorner(Window &win) {
  win.AddCh(ACS_URCORNER);
  return win;
}

ui::Window &ui::AcsVline(Window &win) {
  win.AddCh(ACS_VLINE);
  return win;
}

ui::Window &ui::AcsBbss(Window &win) {
  win.AddCh(ACS_BBSS);
  return win;
}

ui::Window &ui::AcsBlock(Window &win) {
  win.AddCh(ACS_BLOCK);
  return win;
}

ui::Window &ui::AcsBoard(Window &win) {
  win.AddCh(ACS_BOARD);
  return win;
}

ui::Window &ui::AcsBsbs(Window &win) {
  win.AddCh(ACS_BSBS);
  return win;
}

ui::Window &ui::AcsBssb(Window &win) {
  win.AddCh(ACS_BSSB);
  return win;
}

ui::Window &ui::AcsBsss(Window &win) {
  win.AddCh(ACS_BSSS);
  return win;
}

ui::Window &ui::AcsBullet(Window &win) {
  win.AddCh(ACS_BULLET);
  return win;
}

ui::Window &ui::AcsCkboard(Window &win) {
  win.AddCh(ACS_CKBOARD);
  return win;
}

ui::Window &ui::AcsDegree(Window &win) {
  win.AddCh(ACS_DEGREE);
  return win;
}

ui::Window &ui::AcsDiamond(Window &win) {
  win.AddCh(ACS_DIAMOND);
  return win;
}

ui::Window &ui::AcsGequal(Window &win) {
  win.AddCh(ACS_GEQUAL);
  return win;
}

ui::Window &ui::AcsLantern(Window &win) {
  win.AddCh(ACS_LANTERN);
  return win;
}

ui::Window &ui::AcsLarrow(Window &win) {
  win.AddCh(ACS_LARROW);
  return win;
}

ui::Window &ui::AcsLequal(Window &win) {
  win.AddCh(ACS_LEQUAL);
  return win;
}

ui::Window &ui::AcsNequal(Window &win) {
  win.AddCh(ACS_NEQUAL);
  return win;
}

ui::Window &ui::AcsPI(Window &win) {
  win.AddCh(ACS_PI);
  return win;
}

ui::Window &ui::AcsPlminus(Window &win) {
  win.AddCh(ACS_PLMINUS);
  return win;
}

ui::Window &ui::AcsRarrow(Window &win) {
  win.AddCh(ACS_RARROW);
  return win;
}

ui::Window &ui::AcsS1(Window &win) {
  win.AddCh(ACS_S1);
  return win;
}
