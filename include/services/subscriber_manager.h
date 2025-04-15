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

#ifndef SUBSCRIBER_MANAGER_H_
#define SUBSCRIBER_MANAGER_H_

#include <string>
#include <vector>

#include "models/subscriber.h"
#include "models/subscriber_enums.h"

namespace service {

struct SubData {
  std::string nick_name;
  sub::SubLevel sub_level;
  sub::Activity activity;
};

class SubscriberManager {
public:
  void AddSub(SubData sub_data);
  void EditSub(unsigned long long id, SubData sub_data);
  void DelSub(unsigned long long id);

  static int GetMaxLengthNickName() { return kMaxLengthNickName_; }

  const std::vector<const sub::Subscriber *> &GetSubsList() const {
    return subscribers_list_;
  }

  void Sava();
  void Load();

  void SetFilter(sub::Filter filter);
  void SetSort(sub::SortT sort_t);
  void SetGrowth(bool growth);

  void FilterSubscribers();
  void SortSubscribers();

  const sub::Subscriber *const GetSubByID(unsigned long long id) const;

  sub::Filter GetFilter() { return filter_; }
  sub::SortT GetSortT() { return sort_t_; }
  bool GetGrowth() { return growth_; }

private:
  static constexpr int kMaxLengthNickName_ = 22;

  bool growth_ = true;

  sub::Filter filter_ = sub::Filter::kAll;
  sub::SortT sort_t_ = sub::SortT::ID;

  std::vector<const sub::Subscriber *> subscribers_list_;

  std::vector<sub::Subscriber> all_subscribers_list_;

  sub::Subscriber *GetSubByID(unsigned long long id);
  void SortById();
  void SortByData();
  void SortByLikes();
  void SortByNickName();
  void SortByRating();

  std::string GetSubscriberFileName(const sub::Subscriber &sub);
};
} // namespace service

#endif // !SUBSCRIBER_MANAGER_H_
