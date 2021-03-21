#include <gtest/gtest.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  int maxValue(int n, int index, int maxSum) {
    int start = 0, end = maxSum + 1;
    while (start + 1 < end) {
      long mid = (end - start) / 2 + start;
      long sum = calcSum(n, index, mid);
      if (sum > maxSum) {
        end = mid;
      } else {
        start = mid;
      }
    }
    return start;
  }

  long calcSum(int n, int index, int mid/*, int maxSum*/) {
    // n = 6, index = 3
    // 3 4 5 6 5 4
    // 2 3 4 5 4 3
    // 1 2 3 4 3 2
    // 1 1 2 3 2 1
    // 1 1 1 2 1 1
    long sum = mid;
    long min_val = index;
    if (mid > min_val) {
      sum += ((mid - 1) + (mid - min_val)) * min_val / 2;
    } else {
      sum += mid * (mid - 1) / 2;
      sum += min_val - (mid - 1);
    }
    min_val = n - index - 1;
    if (mid > min_val) {
      sum += ((mid - 1) + (mid - min_val)) * min_val / 2;
    } else {
      sum += mid * (mid - 1) / 2;
      sum += min_val - (mid - 1);
    }
    /*
    for (int i = index + 1, val = mid - 1; i < n; ++i, --val) {
      sum += (val >= 2) ? val : 1;
      if (sum > maxSum) { break; }
    }
    for (int i = index - 1, val = mid - 1; i >= 0; --i, --val) {
      sum += (val >= 2) ? val : 1;
      if (sum > maxSum) { break; }
    }
    */
    return sum;
  }
};

int main() {
  Solution sol;
  int n, index, maxSum, expected;

  n = 4, index = 2, maxSum = 6, expected = 2;
  EXPECT_EQ(expected, sol.maxValue(n, index, maxSum));

  n = 6, index = 1, maxSum = 10, expected = 3;
  EXPECT_EQ(expected, sol.maxValue(n, index, maxSum));

  n = 6, index = 2, maxSum = 931384943, expected = 155230825;
  EXPECT_EQ(expected, sol.maxValue(n, index, maxSum));

  n = 9220691, index = 3662083, maxSum = 381489709, expected = 2075627;
  EXPECT_EQ(expected, sol.maxValue(n, index, maxSum));

  exit(EXIT_SUCCESS);
}
