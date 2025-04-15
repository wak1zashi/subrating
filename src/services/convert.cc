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

#include "services/convert.h"

#include <string>

#include "models/subscriber_enums.h"

std::string service::SubLevelToStr(sub::SubLevel level) {
  std::string level_str;

  switch (level) {
  case sub::SubLevel::kStandard:
    level_str = "Standard";
    break;

  case sub::SubLevel::kPremium:
    level_str = "Premium";
    break;

  case sub::SubLevel::kVIP:
    level_str = "VIP";
    break;

  default:
    // no code
    break;
  }

  return level_str;
}

std::string service::FilterToStr(sub::Filter filter) {
  std::string filter_str;

  switch (filter) {
  case sub::Filter::kAll:
    filter_str = "All";
    break;

  case sub::Filter::kStandard:
    filter_str = "Standard";
    break;

  case sub::Filter::kPremium:
    filter_str = "Premium";
    break;

  case sub::Filter::kVIP:
    filter_str = "Vip";
    break;

  default:
    // no code
    break;
  }

  return filter_str;
}

std::string service::SortTToStr(sub::SortT sort_t) {
  std::string sort_t_str;

  switch (sort_t) {
  case sub::SortT::ID:
    sort_t_str = "Id";
    break;

  case sub::SortT::kName:
    sort_t_str = "Name";
    break;

  case sub::SortT::kData:
    sort_t_str = "Data";
    break;

  case sub::SortT::kLikes:
    sort_t_str = "Likes";
    break;

  case sub::SortT::kRating:
    sort_t_str = "Rating";
    break;

  default:
    // no code
    break;
  }

  return sort_t_str;
}
