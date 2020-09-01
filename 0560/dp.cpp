#include <gtest/gtest.h>

#include <iostream>
#include <vector>

using namespace std;

// XXX: TLE
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    size_t m = nums.size();
    vector<vector<int>> dp(m, vector<int>(m, -1));
    int ret = 0;
    for (size_t start = 0; start < m; ++start) {
      for (size_t end = start; end < m; ++end) {
        if (start == end) {
          dp[start][end] = nums[start];
        } else {
          dp[start][end] = dp[start][end-1] + nums[end];
        }
        if (dp[start][end] == k) { ret++; }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int k;

  //  | 0 1
  // ------
  // 0| 1 2
  // 1| 2 1
  nums = {1,1,1};
  k = 2;
  EXPECT_EQ(2, sol.subarraySum(nums, k));

  //  | 0 1 2 3
  // ----------
  // 0| 1 2 4 6
  // 1| - 1 3 5
  // 2| - - 2 4
  // 3| - - - 2
  nums = {1,1,2,2};
  k = 4;
  EXPECT_EQ(2, sol.subarraySum(nums, k));

  //  | 0 1 2 3 4
  // ------------
  // 0| 1 3 4 6 7
  // 1| - 2 3 5 6
  // 2| - - 1 3 4
  // 3| - - - 2 3
  // 4| - - - - 1
  nums = {1,2,1,2,1};
  k = 3;
  EXPECT_EQ(4, sol.subarraySum(nums, k));
}
