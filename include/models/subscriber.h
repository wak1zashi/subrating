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

// This file defines the Subscriber class, responsible for managing subscription
// data,

#ifndef SUBSCRIBER_H_
#define SUBSCRIBER_H_

#include <ctime>

#include <fstream>
#include <string>

#include "activity.h"
#include "subscriber_enums.h"

namespace sub {

class Subscriber {
public:
  Subscriber(std::string nick_name, SubLevel sub_level, Activity activity);

  void UpdateRating();

  void SetNickName(const std::string &nick_name) { nick_name_ = nick_name; }
  void SetSubLevel(SubLevel sub_level) { sub_level_ = sub_level; }

  void SetСommentCount(unsigned int comment_count) {
    activity_.SetСommentCount(comment_count);
  }
  void SetLikesCount(unsigned int likes_count) {
    activity_.SetLikesCount(likes_count);
  }
  void SetViewsCount(unsigned int views_count) {
    activity_.SetViewsCount(views_count);
  }
  void SetTimeSpent(unsigned int time_spent_s) {
    activity_.SetTimeSpent(time_spent_s);
  }

  void SetActivity(Activity ac) { activity_ = ac; }

  const std::string &GetNickName() const { return nick_name_; }
  unsigned int GetId() const { return id_; }
  SubLevel GetSubLevel() const { return sub_level_; }
  time_t GetTime() const { return time_; }
  const std::string &GetStrTime() const { return str_time_; }
  const Activity &GetActivity() const { return activity_; }
  unsigned int GetRating() const { return rating_; }

  static void SavaNextId(std::ofstream &file_stream);
  static void LoadNextId(std::ifstream &file_stream);

  void SavaData(std::ofstream &file_stream) const;
  void LoadData(std::ifstream &file_stream);

private:
  Subscriber();

  static unsigned int next_user_id_;

  std::string nick_name_;
  unsigned int id_;
  SubLevel sub_level_;
  time_t time_;
  std::string str_time_;
  unsigned int rating_;

  Activity activity_;

  void FormatTime();
};

} // namespace sub

#endif // !SUBSCRIBER_H_
