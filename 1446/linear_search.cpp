#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  int maxPower(string s) {
    char prev = '-';
    int ret = 0, count = 0;
    for (const char& c : s) {
      if (c == prev) {
        count++;
      } else {
        prev = c;
        ret = max(ret, count);
        count = 1;
      }
    }
    ret = max(ret, count);
    return ret;
  }
};

int main() {
  Solution sol;
  string s;
  int expected;

  s = "leetcode";
  expected = 2;
  EXPECT_EQ(expected, sol.maxPower(s));

  s = "abbcccddddeeeeedcba";
  expected = 5;
  EXPECT_EQ(expected, sol.maxPower(s));

  s = "triplepillooooow";
  expected = 5;
  EXPECT_EQ(expected, sol.maxPower(s));

  s = "hooraaaaaaaaaaay";
  expected = 11;
  EXPECT_EQ(expected, sol.maxPower(s));

  s = "tourist";
  expected = 1;
  EXPECT_EQ(expected, sol.maxPower(s));

  s = "j";
  expected = 1;
  EXPECT_EQ(expected, sol.maxPower(s));

  exit(EXIT_SUCCESS);
}
