#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    string number = to_string(n);
    const size_t size = number.size();
    vector<int> dp(number.size() + 1);
    dp[size] = 1;
    // when n = 4567, this for loop counts between 1000-4567
    for (int i = size - 1; i >= 0; --i) {
      const int current_digit = static_cast<int>(number[i] - '0');
      for (const string& digit : digits) {
        if (current_digit == stoi(digit)) {
          dp[i] += dp[i+1];
        } else if (current_digit >= stoi(digit)) {
          dp[i] += pow(digits.size(), size - i - 1);
        }
      }
    }
    // when n = 4567, this for loop counts between 1-999
    for (int i = 1; i < size; ++i) {
      dp[0] += pow(digits.size(), i);
    }
    return dp[0];
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
