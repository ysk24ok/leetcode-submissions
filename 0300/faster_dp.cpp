#include <algorithm>
#include <cassert>
#include <iterator>
#include <limits>
#include <vector>

using namespace std;

// dp[i] is the smallest element in nums
// with which increasing substrings whose length is i+1 end.
//  nums: [4, 2, 3, 1, 5]
//  dp[0]: 1
//  dp[1]: 3  (2,3),(2,5),(3,5),(1,5)
//  dp[2]: 5  (2,3,5)
// time complexity: O(nlogn)
// space complexity: O(n)
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
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

  nums = {};
  assert(sol.lengthOfLIS(nums) == 0);

  nums = {2,2};
  assert(sol.lengthOfLIS(nums) == 1);

  nums = {4,2,3,1,5};
  assert(sol.lengthOfLIS(nums) == 3);

  nums = {10,9,2,5,3,7,101,18};
  assert(sol.lengthOfLIS(nums) == 4);

  nums = {1,3,6,7,9,4,10,5,6};
  assert(sol.lengthOfLIS(nums) == 6);
}
