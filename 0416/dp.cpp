#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    sum /= 2;
    vector<bool> dp(sum+1, false);
    dp[0] = true;
    for (int& v : nums) {
      for (int i = v; i <= sum; ++i) {
        dp[i] = dp[i] || dp[i-v];
      }
    }
    return dp[sum];
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {1, 5, 11, 5};
  assert(sol.canPartition(nums));

  nums = {1, 2, 3, 5};
  assert(!sol.canPartition(nums));

  nums = {3, 2, 6, 1};
  assert(sol.canPartition(nums));

  nums = {3, 2, 2, 1};
  assert(sol.canPartition(nums));
}
