#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    return recursive("", digits, n);
  }

  int recursive(const string& number, const vector<string>& digits, long n) {
    if (number != "" && stoll(number) > n) { return 0; }
    int sum = number != "" ? 1 : 0;
    for (const string& digit : digits) {
       sum += recursive(number + digit, digits, n);
    }
    return sum;
  }
};

int main() {
  Solution sol;
  vector<string> digits;
  int n;
  int expected;

  digits = {"1", "3", "5", "7"}, n = 100;
  expected = 20;
  EXPECT_EQ(expected, sol.atMostNGivenDigitSet(digits, n));

  digits = {"1", "4", "9"}, n = 1000000000;
  expected = 29523;
  EXPECT_EQ(expected, sol.atMostNGivenDigitSet(digits, n));

  exit(EXIT_SUCCESS);
}
