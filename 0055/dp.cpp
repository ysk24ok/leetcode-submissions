#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

// XXX: TLE
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    const size_t n = nums.size();
    if (n == 0) { return false; }
    // 0: not reached yet, 1: false, 2: true
    vector<int> dp(n, 0);
    return recursion(nums, dp, 0);
  }

  bool recursion(const vector<int>& nums, vector<int>& dp, int i) {
    if (i >= nums.size()) { return false; }
    else if (i == nums.size() - 1) { return true; }
    if (dp[i] == 2) { return true; }
    else if (dp[i] == 1) { return false; }
    bool ret = false;
    for (int j = 1; j <= nums[i]; ++j) {
      ret |= recursion(nums, dp, i+j);
    }
    dp[i] = ret ? 2 : 1;
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {2,3,1,1,4};
  ExpectEqual(true, sol.canJump(nums));

  nums = {3,2,1,0,4};
  ExpectEqual(false, sol.canJump(nums));

  nums = {};
  ExpectEqual(false, sol.canJump(nums));

  nums = {0};
  ExpectEqual(true, sol.canJump(nums));
}
