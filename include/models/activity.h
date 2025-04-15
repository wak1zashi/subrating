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

// This file defines a class that stores user activity data and provides methods
// to get and set the data.

#ifndef ACTIVITY_H_
#define ACTIVITY_H_

#include <fstream>
#include <iterator>
#include <memory>

namespace sub {

class Activity {
public:
  void SetСommentCount(unsigned int comment_count) {
    comment_count_ = comment_count;
  }
  void SetLikesCount(unsigned int likes_count) { likes_count_ = likes_count; }
  void SetViewsCount(unsigned int views_count) { views_count_ = views_count; }
  void SetTimeSpent(unsigned int time_spent_s) { time_spent_s_ = time_spent_s; }

  unsigned int GetСommentCount() const { return comment_count_; }
  unsigned int GetLikesCount() const { return likes_count_; }
  unsigned int GetViewsCount() const { return views_count_; }
  unsigned int GetTimeSpent() const { return time_spent_s_; }

  void Sava(std::ofstream &file_stream) const {
    file_stream.write(reinterpret_cast<const char *>(&comment_count_),
                      sizeof(comment_count_));
    file_stream.write(reinterpret_cast<const char *>(&likes_count_),
                      sizeof(likes_count_));
    file_stream.write(reinterpret_cast<const char *>(&views_count_),
                      sizeof(views_count_));
    file_stream.write(reinterpret_cast<const char *>(&time_spent_s_),
                      sizeof(time_spent_s_));
  }

  void Load(std::ifstream &file_stream) {
    file_stream.read(reinterpret_cast<char *>(&comment_count_),
                     sizeof(comment_count_));
    file_stream.read(reinterpret_cast<char *>(&likes_count_),
                     sizeof(likes_count_));
    file_stream.read(reinterpret_cast<char *>(&views_count_),
                     sizeof(views_count_));
    file_stream.read(reinterpret_cast<char *>(&time_spent_s_),
                     sizeof(time_spent_s_));
  }

private:
  unsigned int comment_count_ = 0;
  unsigned int likes_count_ = 0;
  unsigned int views_count_ = 0;
  unsigned int time_spent_s_ = 0;
};

} // namespace sub

#endif // ACTIVITY_H_
