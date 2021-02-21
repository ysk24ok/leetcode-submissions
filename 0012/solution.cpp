#include <gtest/gtest.h>

#include <array>
#include <cstdlib>
#include <string>

using namespace std;

const array<char, 7> romans = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

class Solution {
 public:
  string intToRoman(int num) {
    string ret;
    size_t idx = 0;
    while (num > 0) {
      string digit;
      int remainder = num % 10;
      if (remainder == 4) {
        digit += romans[idx];
        digit += romans[idx+1];
      } else if (remainder == 9) {
        digit += romans[idx];
        digit += romans[idx+2];
      } else {
        if (remainder >= 5) {
          digit += romans[idx+1];
          remainder -= 5;
        }
        while (remainder > 0) {
          digit += romans[idx];
          remainder--;
        }
      }
      num /= 10;
      ret = digit + ret;
      idx += 2;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int num;
  string expected;

  num = 3, expected = "III";
  EXPECT_EQ(expected, sol.intToRoman(num));

  num = 4, expected = "IV";
  EXPECT_EQ(expected, sol.intToRoman(num));

  num = 9, expected = "IX";
  EXPECT_EQ(expected, sol.intToRoman(num));

  num = 58, expected = "LVIII";
  EXPECT_EQ(expected, sol.intToRoman(num));

  num = 1994, expected = "MCMXCIV";
  EXPECT_EQ(expected, sol.intToRoman(num));

  exit(EXIT_SUCCESS);
}
