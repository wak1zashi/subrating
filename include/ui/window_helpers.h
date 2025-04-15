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

// This file contains utilities for working with the interface window in the
// console. It includes manipulators for displaying text, as well as symbols
//  for drawing graphical elements of the interface, such as lines, angles
// and other pseudo-graphic elements.

#ifndef WINDOW_HELPERS_H_
#define WINDOW_HELPERS_H_

#include "utils/point.h"

namespace ui {

class Window;

// Ends a line in the window (used with the stream insertion operator).
Window &Endl(Window &win);

// Creates a PointI object (used with the stream insertion operator).
utl::PointI Move(int y, int x);

Window &AcsHline(Window &win);
Window &AcsBtee(Window &win);
Window &AcsLlcorner(Window &win);
Window &AcsLrcorner(Window &win);
Window &AcsLtee(Window &win);
Window &AcsPlus(Window &win);
Window &AcsRtee(Window &win);
Window &AcsTtee(Window &win);
Window &AcsUlcorner(Window &win);
Window &AcsUrcorner(Window &win);
Window &AcsVline(Window &win);
Window &AcsBbss(Window &win);
Window &AcsBlock(Window &win);
Window &AcsBoard(Window &win);
Window &AcsBsbs(Window &win);
Window &AcsBssb(Window &win);
Window &AcsBsss(Window &win);
Window &AcsBullet(Window &win);
Window &AcsCkboard(Window &win);
Window &AcsDegree(Window &win);
Window &AcsDiamond(Window &win);
Window &AcsGequal(Window &win);
Window &AcsLantern(Window &win);
Window &AcsLarrow(Window &win);
Window &AcsLequal(Window &win);
Window &AcsNequal(Window &win);
Window &AcsPI(Window &win);
Window &AcsPlminus(Window &win);
Window &AcsRarrow(Window &win);
Window &AcsS1(Window &win);

} // namespace ui

#endif // !WINDOW_HELPERS_H_
