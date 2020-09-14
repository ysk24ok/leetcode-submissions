#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    const size_t n = nums.size();
    if (n == 0) { return 0; }
    int prev2 = 0, prev1 = nums[0];
    for (size_t i = 2; i <= n; ++i) {
      int curr = max(prev1, prev2 + nums[i-1]);
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

  nums = {1,2,3,1};
  expected = 4;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {2,7,9,3,1};
  expected = 12;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {};
  expected = 0;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {2,1,1,2};
  expected = 4;
  EXPECT_EQ(expected, sol.rob(nums));

  nums = {1,3,1};
  expected = 3;
  EXPECT_EQ(expected, sol.rob(nums));

  exit(EXIT_SUCCESS);
}
