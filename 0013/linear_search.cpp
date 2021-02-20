#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

// I = 1, II = 2, III = 3, IV = 4, V = 5, VI = 6, VII = 7, VIII = 8, IX = 9
// X = 10, XX = 20, XXX = 30, XL = 40, L = 50, LX = 60, LXX = 70, LXXX = 80, XC = 90
// C = 100, CC = 200, CCC = 300, CD = 400, D = 500, DC = 600, DCC = 700, DCCC = 800, CM = 900
const unordered_map<char, int> roman2integer = {
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000}
};

class Solution {
 public:
  int romanToInt(string s) {
    int ret = 0;
    for (size_t i = s.size(); i > 0; --i) {
      if (i < s.size() && roman2integer.at(s[i-1]) < roman2integer.at(s[i])) {
        ret -= roman2integer.at(s[i-1]);
      } else {
        ret += roman2integer.at(s[i-1]);
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s;
  int expected;

  s = "III", expected = 3;
  EXPECT_EQ(expected, sol.romanToInt(s));

  s = "IV", expected = 4;
  EXPECT_EQ(expected, sol.romanToInt(s));

  s = "IX", expected = 9;
  EXPECT_EQ(expected, sol.romanToInt(s));

  s = "LVIII", expected = 58;
  EXPECT_EQ(expected, sol.romanToInt(s));

  s = "MCMXCIV", expected = 1994;
  EXPECT_EQ(expected, sol.romanToInt(s));

  exit(EXIT_SUCCESS);
}
