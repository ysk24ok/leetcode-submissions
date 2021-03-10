#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const size_t n = nums.size();
    vector<int> ret(2);
    for (size_t i = 1; i < n; ++i) {
      if (nums[i] == nums[i-1]) {
        ret[0] = nums[i];
      } else if (nums[i] == nums[i-1] + 2) {
        ret[1] = nums[i-1] + 1;
      }
    }
    if (ret[1] == 0) {
      ret[1] = nums[0] == 1 ? n : 1;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums, expected;

  nums = {1, 2, 2, 4}, expected = {2, 3};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 1}, expected = {1, 2};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 1, 2, 4}, expected = {1, 3};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 2, 3, 3}, expected = {3, 4};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 2, 2, 3}, expected = {2, 4};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {2, 2}, expected = {2, 1};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 3, 3}, expected = {3, 2};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  exit(EXIT_SUCCESS);
}
