#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int zero_counts = 0;
    int insert_at = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        zero_counts++;
      } else {
        nums[insert_at] = nums[i];
        insert_at++;
      }
    }
    for (int i = 0; i < zero_counts; ++i) {
      nums[nums.size()-1-i] = 0;
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums, expected;

  nums = {0,1,0,3,12};
  expected = {1,3,12,0,0};
  sol.moveZeroes(nums);
  assert(equal(nums.begin(), nums.end(), expected.begin()));

  nums = {5,3,1,2,4};
  expected = {5,3,1,2,4};
  sol.moveZeroes(nums);
  assert(equal(nums.begin(), nums.end(), expected.begin()));

  nums = {};
  expected = {};
  sol.moveZeroes(nums);
  assert(equal(nums.begin(), nums.end(), expected.begin()));
}
