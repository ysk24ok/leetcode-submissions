#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    int ret = 0;
    bool is_last_word = true;
    for (const auto& c : s) {
      if (c == ' ') {
        is_last_word = false;
      } else if (!is_last_word) {
        ret = 1;
        is_last_word = true;
      } else {
        ret++;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s;
  int expected;

  s = "Hello World";
  expected = 5;
  EXPECT_EQ(expected, sol.lengthOfLastWord(s));

  s = "Hello";
  expected = 5;
  EXPECT_EQ(expected, sol.lengthOfLastWord(s));

  s = "a ";
  expected = 1;
  EXPECT_EQ(expected, sol.lengthOfLastWord(s));

  exit(EXIT_SUCCESS);
}
