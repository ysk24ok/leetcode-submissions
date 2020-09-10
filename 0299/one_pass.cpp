#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  string getHint(string secret, string guess) {
    int bulls = 0, cows = 0;
    int numbers[10] = {0};
    for (size_t i = 0; i < guess.size(); i++) {
      if (secret[i] == guess[i]) {
        bulls++;
        continue;
      }
      int num1 = int(secret[i]) - int('0');
      int num2 = int(guess[i]) - int('0');
      if (numbers[num1] < 0) {
        cows++;
      }
      if (numbers[num2] > 0) {
        cows++;
      }
      numbers[num1]++;
      numbers[num2]--;
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};

int main() {
  Solution sol;
  string secret, guess, expected;

  secret = "1807", guess = "7810";
  expected = "1A3B";
  EXPECT_EQ(expected, sol.getHint(secret, guess));

  secret = "1123", guess = "0111";
  expected = "1A1B";
  EXPECT_EQ(expected, sol.getHint(secret, guess));

  secret = "11", guess = "10";
  expected = "1A0B";
  EXPECT_EQ(expected, sol.getHint(secret, guess));

  secret = "01", guess = "10";
  expected = "0A2B";
  EXPECT_EQ(expected, sol.getHint(secret, guess));

  secret = "1122", guess = "1222";
  expected = "3A0B";
  EXPECT_EQ(expected, sol.getHint(secret, guess));

  secret = "1122", guess = "1221";
  expected = "2A2B";
  EXPECT_EQ(expected, sol.getHint(secret, guess));

  exit(EXIT_SUCCESS);
}
