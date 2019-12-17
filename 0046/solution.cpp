#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    ret.push_back(nums);
    while (true) {
      int last = 0;
      for (size_t i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] < nums[i+1]) last = i;
      }
      int to_swap = last;
      for (size_t i = last+1; i < nums.size(); ++i) {
        if (nums[last] < nums[i]) to_swap = i;
      }
      if (to_swap == last) {
        break;
      }
      swap(nums[last], nums[to_swap]);
      reverse(nums, last+1);
      ret.push_back(nums);
    }
    return ret;
  }

  void reverse(vector<int>& nums, int idx) {
    int l = idx, r = nums.size() - 1;
    while (l < r) {
      swap(nums[l], nums[r]);
      l++;
      r--;
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  vector<vector<int>> expected;
  vector<vector<int>> got;

  nums = {1,2,3};
  expected = {
    {1,2,3},
    {1,3,2},
    {2,1,3},
    {2,3,1},
    {3,1,2},
    {3,2,1},
  };
  got = sol.permute(nums);
  assert(got == expected);

  nums = {1,2};
  expected = {
    {1,2},
    {2,1}
  };
  got = sol.permute(nums);
  assert(got == expected);
}
