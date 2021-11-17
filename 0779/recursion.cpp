#include <gtest/gtest.h>

using namespace std;

class Solution {
 public:
  int kthGrammar(int n, int k) {
    if (n == 1) {
      return 0;
    }
    int parent = kthGrammar(n - 1, (k + 1) / 2);
    if (parent == 0) {
      return k % 2 == 1 ? 0 : 1;
    } else {
      return k % 2 == 1 ? 1 : 0;
    }
  }
};

int main() {
  Solution sol;
  int n, k, expected;

  n = 1, k = 1, expected = 0;
  EXPECT_EQ(expected, sol.kthGrammar(n, k));

  n = 2, k = 1, expected = 0;
  EXPECT_EQ(expected, sol.kthGrammar(n, k));

  n = 2, k = 2, expected = 1;
  EXPECT_EQ(expected, sol.kthGrammar(n, k));

  n = 3, k = 1, expected = 0;
  EXPECT_EQ(expected, sol.kthGrammar(n, k));

  exit(EXIT_SUCCESS);
}
