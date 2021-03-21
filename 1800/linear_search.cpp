#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int ret = 0;
    int sum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i-1]) {
        sum += nums[i];
      } else {
        ret = max(sum, ret);
        sum = nums[i];
      }
    }
    ret = max(sum, ret);
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {10, 20, 30, 5, 10, 50}, expected = 65;
  EXPECT_EQ(expected, sol.maxAscendingSum(nums));

  nums = {10, 20, 30, 40, 50}, expected = 150;
  EXPECT_EQ(expected, sol.maxAscendingSum(nums));

  nums = {12, 17, 15, 13, 10, 11, 12}, expected = 33;
  EXPECT_EQ(expected, sol.maxAscendingSum(nums));

  nums = {100, 10, 1}, expected = 100;
  EXPECT_EQ(expected, sol.maxAscendingSum(nums));

  exit(EXIT_SUCCESS);
}
