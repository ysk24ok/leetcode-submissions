#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == target) return i;
      else if (target < nums[i]) break;
      else ret++;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {1,3,5,6};
  assert(sol.searchInsert(nums, 0) == 0);
  assert(sol.searchInsert(nums, 1) == 0);
  assert(sol.searchInsert(nums, 2) == 1);
  assert(sol.searchInsert(nums, 3) == 1);
  assert(sol.searchInsert(nums, 4) == 2);
  assert(sol.searchInsert(nums, 5) == 2);
  assert(sol.searchInsert(nums, 7) == 4);

  nums = {};
  assert(sol.searchInsert(nums, 1) == 0);
}
