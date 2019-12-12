#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// time complexity: O(N)
// space complexity: O(2N)
class Solution {
 public:
  int rob(vector<int>& nums) {
    int m = nums.size();
    if (m == 0) return 0;
    if (m == 1) return nums[0];
    if (m == 2) return max(nums[0], nums[1]);
    if (m == 3) return max({nums[0], nums[1], nums[2]});
    int ret = 0;
    vector<int> dp1(m);
    vector<int> dp2(m);
    // nums = {2,7,9,3,1};
    // dp1 -> {2,7,11,10,10}
    // dp2 -> {2,7,9,10,10}
    int cumulative1 = 0;
    int cumulative2 = 0;
    for (int i = 0; i < m; i++) {
      if (i == 0 || i == 1) {
        dp1[i] = nums[i];
        dp2[i] = nums[i];
        ret = max({ret, dp1[i], dp2[i]});
      } else if (i == 2) {
        cumulative1 = max(dp1[i-2], cumulative1);
        dp1[i] = nums[i] + cumulative1;
        dp2[i] = nums[i];
        ret = max({ret, dp1[i], dp2[i]});
      } else if (i == m - 1) {
        cumulative2 = max(dp2[i-2], cumulative2);
        dp2[i] = nums[i] + cumulative2;
        ret = max(ret, dp2[i]);
      } else {
        cumulative1 = max(dp1[i-2], cumulative1);
        cumulative2 = max(dp2[i-2], cumulative2);
        dp1[i] = nums[i] + cumulative1;
        dp2[i] = nums[i] + cumulative2;
        ret = max({ret, dp1[i], dp2[i]});
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {2,1};
  assert(sol.rob(nums) == 2);

  nums = {2,1,1,2};
  assert(sol.rob(nums) == 3);

  nums = {2,3,2};
  assert(sol.rob(nums) == 3);

  nums = {1,2,3,1};
  assert(sol.rob(nums) == 4);

  nums = {1,2,1,1};
  assert(sol.rob(nums) == 3);

  nums = {2,7,9,3,1};
  assert(sol.rob(nums) == 11);
}
