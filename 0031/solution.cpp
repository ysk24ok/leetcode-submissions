#include <gtest/gtest.h>

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() == 1) return;
    int last_idx = -1;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] < nums[i+1]) {
        last_idx = i;
      }
    }
    if (last_idx == (nums.size() - 1) - 1) {
      swap(nums, last_idx, last_idx + 1);
    } else if (last_idx == -1) {
      reverse(nums, 0);
    } else {
      // 2,1,5,4,3 -> 2,3,1,4,5
      // 2,3,5,4,1 -> 2,4,1,3,5
      // 1,5,1 -> 5,1,1
      int idx_to_swap = last_idx + 1;
      for (int i = last_idx + 1; i < nums.size(); i++) {
        if (nums[last_idx] >= nums[i]) break;
        idx_to_swap = i;
      }
      // first, swap 3 and 4
      // 2,3,5,4,1 -> 2,4,5,3,1
      swap(nums, last_idx, idx_to_swap);
      reverse(nums, last_idx + 1);
    }
  }

  void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }

  void reverse(vector<int>&nums, int i) {
    int start_idx = i;
    int end_idx = nums.size() - 1;
    while (start_idx < end_idx) {
      swap(nums, start_idx, end_idx);
      start_idx++;
      end_idx--;
    }
  }
};

int main() {
  Solution sol;
  vector<int> d, expected;

  d = {1}, expected = {1};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {1, 2}, expected = {2, 1};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {1, 2, 3}, expected = {1, 3, 2};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {1, 3, 2}, expected = {2, 1, 3};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {2, 1, 3}, expected = {2, 3, 1};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {2, 3, 1}, expected = {3, 1, 2};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {3, 1, 2}, expected = {3, 2, 1};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {3, 2, 1}, expected = {1, 2, 3};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {1, 1, 5}, expected = {1, 5, 1};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {1, 5, 1}, expected = {5, 1, 1};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {5, 1, 1}, expected = {1, 1, 5};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {1, 2, 3, 4}, expected = {1, 2, 4, 3};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {1, 2, 4, 3}, expected = {1, 3, 2, 4};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  d = {4, 3, 2, 1}, expected = {1, 2, 3, 4};
  sol.nextPermutation(d);
  EXPECT_EQ(expected, d);

  exit(EXIT_SUCCESS);
}
