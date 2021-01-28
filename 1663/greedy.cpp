#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  string getSmallestString(int n, int k) {
    string ret(n, 'a');
    k -= n;
    for (size_t i = n; i > 0; --i) {
      int c = min(k, 25);
      k -= c;
      ret.replace(i - 1, 1, 1, static_cast<char>('a' + c));
      if (k == 0) {
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int n, k;
  string expected;

  n = 3, k = 27, expected = "aay";
  EXPECT_EQ(expected, sol.getSmallestString(n, k));

  n = 5, k = 73, expected = "aaszz";
  EXPECT_EQ(expected, sol.getSmallestString(n, k));

  exit(EXIT_SUCCESS);
}
