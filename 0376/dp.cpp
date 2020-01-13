#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    const size_t n = nums.size();
    if (n < 2) return n;
    vector<int> up(n, 1);
    vector<int> down(n, 1);
    for (size_t i = 1; i < n; ++i) {
      if (nums[i] > nums[i-1]) {  // up
        up[i] = down[i-1] + 1;
        down[i] = down[i-1];
      } else if (nums[i] < nums[i-1]) { // down
        down[i] = up[i-1] + 1;
        up[i] = up[i-1];
      } else {
        up[i] = up[i-1];
        down[i] = down[i-1];
      }
    }
    return max(up[n-1], down[n-1]);
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {1,7,4,9,2,5};
  assert(sol.wiggleMaxLength(nums) == 6);

  nums = {1,17,5,10,13,15,10,5,16,8};
  assert(sol.wiggleMaxLength(nums) == 7);

  nums = {1,2,3,4,5,6,7,8,9};
  assert(sol.wiggleMaxLength(nums) == 2);

  nums = {1};
  assert(sol.wiggleMaxLength(nums) == 1);

  nums = {1,2};
  assert(sol.wiggleMaxLength(nums) == 2);

  nums = {1,1};
  assert(sol.wiggleMaxLength(nums) == 1);
}
