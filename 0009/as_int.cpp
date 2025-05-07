#include <gtest/gtest.h>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0 || (x > 0 && x % 10 == 0)) { return false; }
    int x_copied = x;
    long x_reversed = 0;
    while (x_copied > 0) {
      x_reversed *= 10;
      x_reversed += x_copied % 10;
      x_copied /= 10;
    }
    return x == x_reversed;
  }
};

int main() {
  Solution sol;
  int x;

  x = 121;
  EXPECT_TRUE(sol.isPalindrome(x));

  x = -121;
  EXPECT_FALSE(sol.isPalindrome(x));

  x = 10;
  EXPECT_FALSE(sol.isPalindrome(x));

  x = 0;
  EXPECT_TRUE(sol.isPalindrome(x));

  x = 1234567899;
  EXPECT_FALSE(sol.isPalindrome(x));

  exit(EXIT_SUCCESS);
}
