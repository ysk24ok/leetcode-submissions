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
    const size_t n = nums.size();
    if (n == 0) { return 0; }
    vector<int> dp(n+1, 0);
    dp[1] = nums[0];
    for (size_t i = 2; i <= n; ++i) {
      dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    }
    return dp[n];
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
