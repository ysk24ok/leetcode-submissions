#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int ret = 0;
    int product = 1;
    for (size_t start = 0, end = 0; end < nums.size(); ++end) {
      product *= nums[end];
      while (product >= k && start <= end) {
        product /= nums[start++];
      }
      ret += end - start + 1;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int k;
  int expected;

  nums = {10, 5, 2, 6}, k = 100;
  expected = 8;
  EXPECT_EQ(expected, sol.numSubarrayProductLessThanK(nums, k));

  nums = {1, 8, 2, 3}, k = 7;
  // (1, 2, 3, 2 x 3)
  expected = 4;
  EXPECT_EQ(expected, sol.numSubarrayProductLessThanK(nums, k));

  nums = {2, 3, 8}, k = 7;
  // (2, 3, 2 x 3)
  expected = 3;
  EXPECT_EQ(expected, sol.numSubarrayProductLessThanK(nums, k));

  nums = {10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3}, k = 19;
  // (4 x 3, 3 x 3, 3 x 6, 6 x 2)
  expected = 18;
  EXPECT_EQ(expected, sol.numSubarrayProductLessThanK(nums, k));

  nums = {10,2,2,5,4,4,4,3,7,7}, k = 289;
  expected = 31;
  EXPECT_EQ(expected, sol.numSubarrayProductLessThanK(nums, k));

  exit(EXIT_SUCCESS);
}
