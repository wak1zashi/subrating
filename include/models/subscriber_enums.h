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

#ifndef SUBSCRIBER_ENUMS_H_
#define SUBSCRIBER_ENUMS_H_

#include <alloca.h>
namespace sub {

enum class SubLevel { kStandard, kPremium, kVIP };

enum class Filter { kAll, kStandard, kPremium, kVIP };

enum class SortT { ID, kName, kData, kLikes, kRating };

} // namespace sub

#endif // !SUBSCRIBER_ENUMS_H_
