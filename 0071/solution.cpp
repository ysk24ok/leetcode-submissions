#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    vector<pair<size_t, size_t>> dirs;
    size_t prev = 0;
    size_t len = 0;
    for (size_t curr = 1; curr <= path.length(); curr++) {
      if (curr < path.length() && path[curr] != '/') { continue; }
      if (curr - prev == 1 || (curr - prev == 2 && path[curr-1] == '.')) {
        prev = curr;
      } else if (curr - prev == 3 && path[curr-1] == '.' && path[curr-2] == '.') {
        if (!dirs.empty()) {
          size_t dir_len = dirs[dirs.size()-1].second;
          dirs.pop_back();
          len -= dir_len + 1;
        }
        prev = curr;
      } else {
        size_t dir_len = curr - prev - 1;
        dirs.push_back({prev + 1, dir_len});
        len += dir_len + 1;
        prev = curr;
      }
    }
    if (dirs.empty()) { return "/"; }
    string simplified(len, '/');
    size_t i = 1;
    for (const auto& dir : dirs) {
      size_t pos = dir.first;
      size_t dir_len = dir.second;
      simplified.replace(i, dir_len, path, pos, dir_len);
      i += dir_len + 1;
    }
    return simplified;
  }
};

int main() {
  Solution sol;
  string path, expected;

  path = "/home/", expected = "/home";
  EXPECT_EQ(sol.simplifyPath(path), expected);

  path = "/home//foo", expected = "/home/foo";
  EXPECT_EQ(sol.simplifyPath(path), expected);

  path = "/home/user/Documents/../Pictures", expected = "/home/user/Pictures";
  EXPECT_EQ(sol.simplifyPath(path), expected);

  path = "/../", expected = "/";
  EXPECT_EQ(sol.simplifyPath(path), expected);

  path = "/.../a/../b/c/../d/./", expected = "/.../b/d";
  EXPECT_EQ(sol.simplifyPath(path), expected);

  exit(EXIT_SUCCESS);
}
