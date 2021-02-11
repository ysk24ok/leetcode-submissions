#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] != t[i]) {
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

  s = "anagram", t = "nagarama", expected = true;
  EXPECT_EQ(expected, sol.isAnagram(s, t));

  exit(EXIT_SUCCESS);
}
