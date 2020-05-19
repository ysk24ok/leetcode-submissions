#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) { return false; }
    unordered_map<char, int> count;
    for (const char& c : s1) { count[c]++; }
    size_t start = 0, end = 0;
    int diff = s1.size();
    for (end = 0; end < s1.size(); ++end) {
      count[s2[end]]--;
      if (count[s2[end]] >= 0) { --diff; }
    }
    if (diff == 0) { return true; }
    while (end < s2.size()) {
      const char& start_char = s2[start];
      if (count[start_char] >= 0) { ++diff; }
      ++count[start_char];
      ++start;
      const char& end_char = s2[end];
      --count[end_char];
      if (count[end_char] >= 0) { --diff; }
      ++end;
      if (diff == 0) { return true; }
    }
    return false;
  }
};

int main() {
  Solution sol;
  string s1, s2;

  s1 = "ab", s2 = "badcea";
  EXPECT_TRUE(sol.checkInclusion(s1, s2));

  s1 = "ab", s2 = "eidbaooo";
  EXPECT_TRUE(sol.checkInclusion(s1, s2));

  s1 = "ab", s2 = "eidboaoo";
  EXPECT_FALSE(sol.checkInclusion(s1, s2));

  s1 = "dinitrophenylhydrazine", s2 = "dimethylhydrazine";
  EXPECT_FALSE(sol.checkInclusion(s1, s2));

  exit(EXIT_SUCCESS);
}
