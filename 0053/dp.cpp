#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    // dp[i] means maximum sum of subarray
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int max_sum = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      // when dp[i - 1] < 0, subarray starts from i
      int sum_so_far = dp[i - 1] > 0 ? dp[i - 1] : 0;
      dp[i] = nums[i] + sum_so_far;
      if (dp[i] > max_sum) max_sum = dp[i];
    }
    return max_sum;
  }
};

int main() {
  Solution sol;
  vector<int> d;

  d = {};
  assert(sol.maxSubArray(d) == 0);

  d = {-2};
  assert(sol.maxSubArray(d) == -2);

  d = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  assert(sol.maxSubArray(d) == 6);
}
