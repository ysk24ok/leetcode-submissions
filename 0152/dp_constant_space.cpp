#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 0) { return 0; }
    int prev_max = 1, prev_min = 1, curr_max = 0, curr_min = 0;
    int ret = numeric_limits<int>::min();
    for (size_t i = 0; i < nums.size(); i++) {
      int val1 = prev_max * nums[i];
      int val2 = prev_min * nums[i];
      curr_max = max({nums[i], val1, val2});
      curr_min = min({nums[i], val1, val2});
      ret = max(curr_max, ret);
      prev_max = curr_max;
      prev_min = curr_min;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {2, 3, -2, 4};
  expected = 6;
  EXPECT_EQ(expected, sol.maxProduct(nums));

  nums = {-2, 0, -1};
  expected = 0;
  EXPECT_EQ(expected, sol.maxProduct(nums));

  nums = {-2};
  expected = -2;
  EXPECT_EQ(expected, sol.maxProduct(nums));

  nums = {-4, -3, -2};
  expected = 12;
  EXPECT_EQ(expected, sol.maxProduct(nums));

  exit(EXIT_SUCCESS);
}
