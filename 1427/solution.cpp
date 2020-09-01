#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string stringShift(string s, vector<vector<int>>& shift) {
    int start = 0;
    for (const auto& pair : shift) {
      if (pair[0] == 0) { start += pair[1]; }
      else { start -= pair[1]; }
    }
    while (start < 0) { start += s.size(); }
    while (start >= s.size()) { start -= s.size(); }
    return string(s.begin() + start, s.end()) + string(s.begin(), s.begin() + start);
  }
};

int main() {
  Solution sol;
  string s, expected;
  vector<vector<int>> shift;

  s = "abc";
  shift = {{0,1},{1,2}};
  expected = "cab";
  EXPECT_EQ(expected, sol.stringShift(s, shift));

  s = "abcdefg";
  shift = {{1,1},{1,1},{0,2},{1,3}};
  expected = "efgabcd";
  EXPECT_EQ(expected, sol.stringShift(s, shift));

  s = "yisxjwry";
  shift = {{1,8},{1,4},{1,3},{1,6},{0,6},{1,4},{0,2},{0,1}};
  expected = "yisxjwry";
  EXPECT_EQ(expected, sol.stringShift(s, shift));

  s = "xqgwkiqpif";
  shift = {{1,4},{0,7},{0,8},{0,7},{0,6},{1,3},{0,1},{1,7},{0,5},{0,6}};
  expected = "qpifxqgwki";
  EXPECT_EQ(expected, sol.stringShift(s, shift));
}
