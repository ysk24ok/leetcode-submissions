#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

// time complexity: O(N)
// space complexity: O(N)
class Solution {
 public:
  int rob(vector<int>& nums) {
    int m = nums.size();
    if (m == 0) return 0;
    if (m == 1) return nums[0];
    if (m == 2) return max(nums[0], nums[1]);
    vector<int> dp(m);
    dp[0] = nums[0];
    dp[1] = nums[1];
    int ret = max(dp[0], dp[1]);
    int max_sofar = 0;
    // dp[i] = nums[i] + max(dp[i-2], dp[i-3], dp[i-4], ...);
    for (int i = 2; i < m; i++) {
      max_sofar = max(dp[i-2], max_sofar);
      dp[i] = nums[i] + max_sofar;
      ret = max(ret, dp[i]);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {1,2,3,1};
  assert(sol.rob(nums) == 4);

  nums = {2,7,9,3,1};
  assert(sol.rob(nums) == 12);

  nums = {};
  assert(sol.rob(nums) == 0);

  nums = {2,1,1,2};
  assert(sol.rob(nums) == 4);

  nums = {1,3,1};
  assert(sol.rob(nums) == 3);
}
