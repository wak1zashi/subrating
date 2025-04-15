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

#ifndef CONVERT_H_
#define CONVERT_H_

#include <string>

#include "models/subscriber_enums.h"

namespace service {

std::string SubLevelToStr(sub::SubLevel level);

std::string FilterToStr(sub::Filter filter);

std::string SortTToStr(sub::SortT sort_t);

} // namespace service

#endif // !CONVERT_H_
