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

#include "services/subscriber_manager.h"

#include <algorithm>
#include <ncurses.h>
#include <sstream>
#include <string>

#include "models/subscriber.h"
#include "models/subscriber_enums.h"
#include "utils/file_utils.h"

void service::SubscriberManager::AddSub(SubData sub_data) {
  all_subscribers_list_.emplace_back(sub::Subscriber(
      sub_data.nick_name, sub_data.sub_level, sub_data.activity));
  FilterSubscribers();
}
void service::SubscriberManager::EditSub(unsigned long long id,
                                         SubData sub_data) {
  sub::Subscriber *sub = GetSubByID(id);

  if (sub != nullptr) {
    sub->SetNickName(sub_data.nick_name);
    sub->SetSubLevel(sub_data.sub_level);
    sub->SetActivity(sub_data.activity);
    sub->UpdateRating();
  }

  FilterSubscribers();
}

void service::SubscriberManager::DelSub(unsigned long long id) {
  auto it = std::find_if(
      all_subscribers_list_.begin(), all_subscribers_list_.end(),
      [id](const sub::Subscriber &sub) { return sub.GetId() == id; });

  if (it != all_subscribers_list_.end()) {
    all_subscribers_list_.erase(it);
  }

  FilterSubscribers();
}

void service::SubscriberManager::Sava() {
  for (const auto &sub : all_subscribers_list_) {
    utl::Sava(GetSubscriberFileName(sub), sub);
  }
  utl::SavaNextId();
}

void service::SubscriberManager::Load() {
  auto files = utl::GetSubscriberBitFiles();

  sub::Subscriber temp_sub("none", sub::SubLevel::kStandard, sub::Activity());
  all_subscribers_list_.clear();

  for (const auto &file : files) {

    std::string path = "data/" + file;

    utl::Load(path, temp_sub);
    all_subscribers_list_.emplace_back(temp_sub);
  }

  utl::LoadNextId();
  FilterSubscribers();
}

void service::SubscriberManager::SetFilter(sub::Filter filter) {
  filter_ = filter;
  FilterSubscribers();
}

void service::SubscriberManager::SetSort(sub::SortT sort_t) {
  sort_t_ = sort_t;
  SortSubscribers();
}

void service::SubscriberManager::SetGrowth(bool growth) {
  growth_ = growth;
  SortSubscribers();
}

void service::SubscriberManager::FilterSubscribers() {
  auto matches_filter = [this](const sub::Subscriber &sub) {
    return filter_ == sub::Filter::kAll ||
           (filter_ == sub::Filter::kStandard &&
            sub.GetSubLevel() == sub::SubLevel::kStandard) ||
           (filter_ == sub::Filter::kPremium &&
            sub.GetSubLevel() == sub::SubLevel::kPremium) ||
           (filter_ == sub::Filter::kVIP &&
            sub.GetSubLevel() == sub::SubLevel::kVIP);
  };

  subscribers_list_.clear();
  for (const auto &sub : all_subscribers_list_) {
    if (matches_filter(sub)) {
      subscribers_list_.push_back(&sub);
    }
  }

  SortSubscribers();
}

void service::SubscriberManager::SortSubscribers() {
  switch (sort_t_) {
  case sub::SortT::ID:
    SortById();
    break;

  case sub::SortT::kData:
    SortByData();
    break;

  case sub::SortT::kLikes:
    SortByLikes();
    break;

  case sub::SortT::kName:
    SortByNickName();
    break;

  case sub::SortT::kRating:
    SortByRating();
    break;
  }
}

const sub::Subscriber *const
service::SubscriberManager::GetSubByID(unsigned long long id) const {
  auto it = std::find_if(
      all_subscribers_list_.begin(), all_subscribers_list_.end(),
      [id](const sub::Subscriber &sub) { return sub.GetId() == id; });

  return (it != all_subscribers_list_.end()) ? &(*it) : nullptr;
}

sub::Subscriber *service::SubscriberManager::GetSubByID(unsigned long long id) {
  auto it = std::find_if(
      all_subscribers_list_.begin(), all_subscribers_list_.end(),
      [id](const sub::Subscriber &sub) { return sub.GetId() == id; });

  return (it != all_subscribers_list_.end()) ? &(*it) : nullptr;
}

void service::SubscriberManager::SortById() {
  std::sort(
      subscribers_list_.begin(), subscribers_list_.end(),
      [this](const sub::Subscriber *first, const sub::Subscriber *second) {
        return growth_ ? first->GetId() < second->GetId()
                       : first->GetId() > second->GetId();
      });
}

void service::SubscriberManager::SortByData() {
  std::sort(
      subscribers_list_.begin(), subscribers_list_.end(),
      [this](const sub::Subscriber *first, const sub::Subscriber *second) {
        return growth_ ? first->GetTime() < second->GetTime()
                       : first->GetTime() > second->GetTime();
      });
}

void service::SubscriberManager::SortByLikes() {
  std::sort(
      subscribers_list_.begin(), subscribers_list_.end(),
      [this](const sub::Subscriber *first, const sub::Subscriber *second) {
        return growth_ ? first->GetActivity().GetLikesCount() <
                             second->GetActivity().GetLikesCount()
                       : first->GetActivity().GetLikesCount() >
                             second->GetActivity().GetLikesCount();
      });
}

void service::SubscriberManager::SortByNickName() {
  std::sort(
      subscribers_list_.begin(), subscribers_list_.end(),
      [this](const sub::Subscriber *first, const sub::Subscriber *second) {
        return growth_ ? first->GetNickName() < second->GetNickName()
                       : first->GetNickName() > second->GetNickName();
      });
}

void service::SubscriberManager::SortByRating() {
  std::sort(
      subscribers_list_.begin(), subscribers_list_.end(),
      [this](const sub::Subscriber *first, const sub::Subscriber *second) {
        return growth_ ? first->GetRating() < second->GetRating()
                       : first->GetRating() > second->GetRating();
      });
}

std::string
service::SubscriberManager::GetSubscriberFileName(const sub::Subscriber &sub) {
  std::ostringstream oss;

  oss << "data/subscriber_" << sub.GetId() << ".bit";

  return oss.str();
}
