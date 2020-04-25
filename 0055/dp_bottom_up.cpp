#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    const size_t n = nums.size();
    if (n == 0) { return false; }
    // 0: not reached yet, 1: false, 2: true
    vector<int> dp(n, 0);
    dp[n-1] = 2;
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 1; j <= nums[i]; ++j) {
        if (i + j >= n) { continue; }
        if (dp[i + j] == 2) {
          dp[i] = 2;
          break;
        }
      }
    }
    return dp[0] == 2;
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
