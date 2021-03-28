#include <gtest/gtest.h>

#include <array>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  string originalDigits(string s) {
    array<size_t, 10> counter = {0};
    for (const char& c : s) {
      if (c == 'z') counter[0]++;
      if (c == 'w') counter[2]++;
      if (c == 'u') counter[4]++;
      if (c == 'x') counter[6]++;
      if (c == 'g') counter[8]++;
      if (c == 'f') counter[5]++;  // 4, 5
      if (c == 'v') counter[7]++;  // 5, 7
      if (c == 'h') counter[3]++;  // 3, 8
      if (c == 'o') counter[1]++;  // 0, 1, 2, 4
      if (c == 'i') counter[9]++;  // 5, 6, 8, 9
    }
    counter[5] -= counter[4];
    counter[7] -= counter[5];
    counter[3] -= counter[8];
    counter[1] -= (counter[0] + counter[2] + counter[4]);
    counter[9] -= (counter[5] + counter[6] + counter[8]);
    string ret;
    for (size_t i = 0; i < counter.size(); ++i) {
      for (size_t j = 0; j < counter[i]; ++j) {
        ret += to_string(i);
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s, expected;

  s = "owoztneoer", expected = "012";
  EXPECT_EQ(expected, sol.originalDigits(s));

  s = "fviefuro", expected = "45";
  EXPECT_EQ(expected, sol.originalDigits(s));

  s = "vfie", expected = "5";
  EXPECT_EQ(expected, sol.originalDigits(s));

  s = "ofur", expected = "4";
  EXPECT_EQ(expected, sol.originalDigits(s));

  exit(EXIT_SUCCESS);
}
