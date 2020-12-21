#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int smallestRangeII(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int left_min = A[0] + K, right_max = A[A.size()-1] - K;
    int ret = A[A.size()-1] - A[0];
    for (size_t i = 0; i < A.size() - 1; ++i) {
      int left_max = A[i] + K, right_min = A[i+1] - K;
      int maxval = max(left_max, right_max);
      int minval = min(left_min, right_min);
      ret = min(maxval - minval, ret);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> A;
  int K, expected;

  A = {1}, K = 0, expected = 0;
  EXPECT_EQ(expected, sol.smallestRangeII(A, K));

  A = {0, 10}, K = 2, expected = 6;
  EXPECT_EQ(expected, sol.smallestRangeII(A, K));

  A = {1, 3, 6}, K = 3, expected = 3;
  EXPECT_EQ(expected, sol.smallestRangeII(A, K));

  exit(EXIT_SUCCESS);
}
