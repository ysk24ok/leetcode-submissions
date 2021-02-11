#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    array<int, 26> counts = {0};
    for (size_t i = 0; i < s.size(); ++i) {
      counts[s[i] - 'a']++;
      counts[t[i] - 'a']--;
    }
    for (const int& count : counts) {
      if (count != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string s, t;
  bool expected;

  s = "anagram", t = "nagaram", expected = true;
  EXPECT_EQ(expected, sol.isAnagram(s, t));

  s = "anagram", t = "nagarama", expected = false;
  EXPECT_EQ(expected, sol.isAnagram(s, t));

  exit(EXIT_SUCCESS);
}
