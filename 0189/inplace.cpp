#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    rotate(nums, 0, nums.size()-1, k);
  }

  void rotate(vector<int>& nums, int start, int end, int k) {
    if (start >= end) { return; }
    const int n = end - start + 1;
    k %= n;
    if (k == 0) { return; }
    for (int i = start; i < start + k; ++i) {
      swap(nums, i, i - k + n);
    }
    rotate(nums, start + k, end, k);
  }

  void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
};

int main() {
  Solution sol;
  vector<int> nums, expected;
  int k;

  // 1,2,3,4,5,6,7
  // 5,2,3,4,1,6,7
  // 5,6,7,4,1,2,3
  // 5,6,7,1,4,2,3
  // 5,6,7,1,2,4,3
  // 5,6,7,1,2,3,4
  nums = {1, 2, 3, 4, 5, 6, 7}, k = 3;
  expected = {5, 6, 7, 1, 2, 3, 4};
  sol.rotate(nums, k);
  EXPECT_EQ(expected, nums);

  // 1,2,3,4,5,6,7
  // 6,2,3,4,5,1,7
  // 6,7,3,4,5,1,2
  // 6,7,1,4,5,3,2
  // 6,7,1,2,5,3,4
  // 6,7,1,2,3,5,4
  // 6,7,1,2,3,4,5
  nums = {1, 2, 3, 4, 5, 6, 7}, k = 2;
  expected = {6, 7, 1, 2, 3, 4, 5};
  sol.rotate(nums, k);
  EXPECT_EQ(expected, nums);

  // 1,2,3,4,5,6,7
  // 2,3,4,5,6,7,1
  nums = {1, 2, 3, 4, 5, 6, 7}, k = 6;
  expected = {2, 3, 4, 5, 6, 7, 1};
  sol.rotate(nums, k);
  EXPECT_EQ(expected, nums);

  // 1,2,3,4
  // 3,2,1,4
  // 3,4,1,2
  nums = {-1, -100, 3, 99}, k = 2;
  expected = {3, 99, -1, -100};
  sol.rotate(nums, k);
  EXPECT_EQ(expected, nums);

  nums = {1, 2}, k = 0;
  expected = {1, 2};
  sol.rotate(nums, k);
  EXPECT_EQ(expected, nums);

  nums = {1, 2}, k = 2;
  expected = {1, 2};
  sol.rotate(nums, k);
  EXPECT_EQ(expected, nums);

  nums = {1, 2, 3, 4, 5, 6}, k = 4;
  expected = {3, 4, 5, 6, 1, 2};
  sol.rotate(nums, k);
  EXPECT_EQ(expected, nums);

  exit(EXIT_SUCCESS);
}
