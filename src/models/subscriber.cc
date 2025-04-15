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

#include "models/subscriber.h"
#include "models/activity.h"
#include "models/subscriber_enums.h"

#include <ctime>

#include <fstream>
#include <string>

unsigned int sub::Subscriber::next_user_id_ = 1;

sub::Subscriber::Subscriber()
    : nick_name_("none"), id_(0), sub_level_(sub::SubLevel::kStandard),
      time_(0), str_time_("none"), rating_(0) {}

sub::Subscriber::Subscriber(std::string nick_name, SubLevel sub_level,
                            Activity activity)
    : nick_name_(nick_name), sub_level_(sub_level), id_(next_user_id_++),
      activity_(activity), rating_(0) {
  std::time(&time_);

  FormatTime();
  UpdateRating();
}

void sub::Subscriber::UpdateRating() {
  rating_ += activity_.GetLikesCount() * 1;
  rating_ += activity_.GetСommentCount() * 2;
  rating_ += activity_.GetViewsCount() * 0.5;
  rating_ += activity_.GetTimeSpent() * 0.003;
}

void sub::Subscriber::SavaNextId(std::ofstream &file_stream) {
  file_stream.write(reinterpret_cast<const char *>(&next_user_id_),
                    sizeof(next_user_id_));
}

void sub::Subscriber::LoadNextId(std::ifstream &file_stream) {
  file_stream.read(reinterpret_cast<char *>(&next_user_id_),
                   sizeof(next_user_id_));
}

void sub::Subscriber::SavaData(std::ofstream &file_stream) const {
  std::string::size_type nick_name_length = nick_name_.length();
  file_stream.write(reinterpret_cast<const char *>(&nick_name_length),
                    sizeof(nick_name_length));
  file_stream.write(nick_name_.c_str(), nick_name_length);

  file_stream.write(reinterpret_cast<const char *>(&id_), sizeof(id_));

  int sub_level = static_cast<unsigned int>(sub_level_);
  file_stream.write(reinterpret_cast<const char *>(&sub_level),
                    sizeof(sub_level));

  file_stream.write(reinterpret_cast<const char *>(&time_), sizeof(time_));

  file_stream.write(reinterpret_cast<const char *>(&rating_), sizeof(rating_));

  activity_.Sava(file_stream);
}

void sub::Subscriber::LoadData(std::ifstream &file_stream) {

  std::string::size_type nick_name_length;
  file_stream.read(reinterpret_cast<char *>(&nick_name_length),
                   sizeof(nick_name_length));
  nick_name_.resize(nick_name_length);
  file_stream.read(&nick_name_[0], nick_name_length);

  file_stream.read(reinterpret_cast<char *>(&id_), sizeof(id_));

  int sub_level = static_cast<unsigned int>(sub_level_);
  file_stream.read(reinterpret_cast<char *>(&sub_level), sizeof(sub_level));
  sub_level_ = static_cast<sub::SubLevel>(sub_level);

  file_stream.read(reinterpret_cast<char *>(&time_), sizeof(time_));

  file_stream.read(reinterpret_cast<char *>(&rating_), sizeof(rating_));

  activity_.Load(file_stream);

  FormatTime();
}

void sub::Subscriber::FormatTime() {
  str_time_ = std::ctime(&time_);

  if (!str_time_.empty() && str_time_.back() == '\n') {
    str_time_.pop_back();
  }
}
