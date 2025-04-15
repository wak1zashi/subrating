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

#ifndef FILE_UTILS_H_
#define FILE_UTILS_H_

#include "models/subscriber.h"

#include <string>
#include <vector>

namespace utl {

struct FileData {
  std::string file_name;
  std::string content;
};

bool Sava(const FileData &data);
bool Load(FileData &data);

bool Sava(std::string file_name, const sub::Subscriber &sub);
bool Load(std::string file_name, sub::Subscriber &sub);

bool SavaNextId();
bool LoadNextId();

std::vector<std::string> GetSubscriberBitFiles();

} // namespace utl

#endif // !FILE_UTILS_H_
