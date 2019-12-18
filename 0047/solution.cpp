#include <algorithm>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    ret.push_back(nums);
    int left, right;
    while (true) {
      left = 0;
      for (int i = 0; i < nums.size()-1; ++i) {
        if (nums[i] < nums[i+1]) left = i;
      }
      right = left;
      for (int i = left+1; i < nums.size(); ++i) {
        if (nums[left] < nums[i]) right = i;
      }
      if (left == right) break;
      swap(nums[left], nums[right]);
      reverse(nums, left+1);
      ret.push_back(nums);
    }
    return ret;
  }

  void reverse(vector<int>& nums, int idx) {
    int l = idx, r = nums.size()-1;
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
  vector<vector<int>> got, expected;

  nums = {1,2,1};
  got = sol.permuteUnique(nums);
  expected = {
    {1,1,2},
    {1,2,1},
    {2,1,1}
  };
  assert(got == expected);

  nums = {1,2};
  got = sol.permuteUnique(nums);
  expected = {
    {1,2},
    {2,1}
  };
  assert(got == expected);

  nums = {1,2,3};
  expected = {
    {1,2,3},
    {1,3,2},
    {2,1,3},
    {2,3,1},
    {3,1,2},
    {3,2,1},
  };
  got = sol.permuteUnique(nums);
  assert(got == expected);

  nums = {1,1,2,2};
  expected = {
    {1,1,2,2},
    {1,2,1,2},
    {1,2,2,1},
    {2,1,1,2},
    {2,1,2,1},
    {2,2,1,1}
  };
  got = sol.permuteUnique(nums);
  assert(got == expected);
}
