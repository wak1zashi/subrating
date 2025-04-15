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

#include "utils/file_utils.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>

bool utl::Sava(const FileData &data) {
  std::ofstream fileStream(data.file_name);

  if (!fileStream.is_open()) {
    return false;
  }

  fileStream << data.content;

  return true;
}

bool utl::Load(FileData &data) {
  std::ifstream file_stream(data.file_name);

  if (!file_stream.is_open()) {
    return false;
  }

  data.content.clear();

  std::string line;

  for (; !file_stream.eof();) {
    std::getline(file_stream, line);
    line.push_back('\n');
    data.content += line;
  }

  return true;
}

bool utl::Sava(std::string file_name, const sub::Subscriber &sub) {
  std::ofstream file_stream(file_name, std::ios::binary);

  if (!file_stream.is_open()) {
    return false;
  }

  sub.SavaData(file_stream);

  return true;
}

bool utl::Load(std::string file_name, sub::Subscriber &sub) {
  std::ifstream file_stream(file_name, std::ios::binary);

  if (!file_stream.is_open()) {
    return false;
  }

  sub.LoadData(file_stream);

  return true;
}

bool utl::SavaNextId() {
  std::ofstream file_stream("data/sub_next_id.bit", std::ios::binary);

  if (!file_stream.is_open()) {
    return false;
  }

  sub::Subscriber::SavaNextId(file_stream);

  return true;
}

bool utl::LoadNextId() {
  std::ifstream file_stream("data/sub_next_id.bit", std::ios::binary);

  if (!file_stream.is_open()) {
    return false;
  }

  sub::Subscriber::LoadNextId(file_stream);

  return true;
}

std::vector<std::string> utl::GetSubscriberBitFiles() {
  std::string folder = "data/";
  std::vector<std::string> files;

  for (const auto &entry : std::filesystem::directory_iterator(folder)) {
    std::string filename = entry.path().filename().string();

    if (filename.rfind("subscriber_", 0) == 0 && filename.ends_with(".bit")) {
      files.push_back(filename);
    }
  }

  std::sort(files.begin(), files.end(),
            [](const std::string &a, const std::string &b) {
              int numA = std::stoi(a.substr(11, a.find(".bit") - 11));
              int numB = std::stoi(b.substr(11, b.find(".bit") - 11));
              return numA < numB;
            });

  return files;
}
