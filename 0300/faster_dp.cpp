#include <gtest/gtest.h>

#include <algorithm>
#include <iterator>
#include <limits>
#include <vector>

using namespace std;

// `dp` stores an increasing substring.
// At every `i`, we can use binary search
// to find where to insert `nums[i]`.
//
// Say nums = [4, 2, 3, 1, 5],
//   i = 0: dp = [4]
//   i = 1: dp = [2]
//   i = 2: dp = [2, 3]
//   i = 3: dp = [1, 3]
//   i = 4: dp = [1, 3, 5]
//
// time complexity: O(N * logN)
// space complexity: O(N)
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), numeric_limits<int>::max());
    int ret = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
      int idx = distance(dp.begin(), it);
      dp[idx] = nums[i];
      ret = max(idx, ret);
    }
    return ret + 1;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {2, 2};
  expected = 1;
  EXPECT_EQ(expected, sol.lengthOfLIS(nums));

  nums = {4, 2, 3, 1, 5};
  expected = 3;
  EXPECT_EQ(expected, sol.lengthOfLIS(nums));

  nums = {10, 9, 2, 5, 3, 7, 101, 18};
  expected = 4;
  EXPECT_EQ(expected, sol.lengthOfLIS(nums));

  nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  expected = 6;
  EXPECT_EQ(expected, sol.lengthOfLIS(nums));
}
