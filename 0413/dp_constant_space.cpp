#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int ret = 0;
    // Actually one `dp` variable is enough.
    int dp_prev = 0, dp_curr = 0, dp_next = 0;
    for (size_t i = 2; i < A.size(); ++i) {
      if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
        dp_next = dp_curr * 2 - dp_prev + 1;
        dp_prev = dp_curr;
        dp_curr = dp_next;
      } else {
        ret += dp_curr;
        dp_prev = 0, dp_curr = 0;
      }
    }
    ret += dp_curr;
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> A;
  int expected;

  A = {1, 2, 3, 4}, expected = 3;
  EXPECT_EQ(expected, sol.numberOfArithmeticSlices(A));

  A = {1, 2, 3}, expected = 1;
  EXPECT_EQ(expected, sol.numberOfArithmeticSlices(A));

  A = {1, 2}, expected = 0;
  EXPECT_EQ(expected, sol.numberOfArithmeticSlices(A));

  A = {1, 2, 3, 5}, expected = 1;
  EXPECT_EQ(expected, sol.numberOfArithmeticSlices(A));

  A = {1, 2, 3, 5, 7}, expected = 2;
  EXPECT_EQ(expected, sol.numberOfArithmeticSlices(A));

  exit(EXIT_SUCCESS);
}
