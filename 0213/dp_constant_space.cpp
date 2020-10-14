#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    const size_t n = nums.size();
    if (n == 1) { return nums[0]; }
    return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
  }

  int rob(vector<int>& nums, size_t start, size_t end) {
    if (start == end) { return nums[start]; }
    int prev2 = 0, prev1 = nums[start], curr;
    for (size_t i = start+1; i <= end; ++i) {
      curr = max(prev2 + nums[i], prev1);
      prev2 = prev1;
      prev1 = curr;
    }
    return prev1;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {2, 1};
  expected = 2;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {2, 1, 1, 2};
  expected = 3;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {2, 3, 2};
  expected = 3;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {1, 2, 3, 1};
  expected = 4;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {1, 2, 1, 1};
  expected = 3;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {2, 7, 9, 3, 1};
  expected = 11;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {1, 3, 1, 3, 100};
  expected = 103;
  EXPECT_EQ(expected, sol.rob(nums));

  exit(EXIT_SUCCESS);
}
