#include <cassert>
#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    const size_t m = nums.size();
    for (size_t i = 0; i < m - 1; ++i) {
      size_t min_idx = i;
      for (size_t j = i + 1; j < m; ++j) {
        if (nums[min_idx] > nums[j]) {
          min_idx = j;
        }
      }
      swap(nums, i, min_idx);
    }
    return nums;
  }

 private:
  void swap(vector<int>& nums, size_t i, size_t j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
};

int main() {
  Solution sol;
  vector<int> nums, expected;

  nums = {5,2,3,1};
  expected = {1,2,3,5};
  EXPECT_EQ(expected, sol.sortArray(nums));

  nums = {5,1,1,2,0,0};
  expected = {0,0,1,1,2,5};
  EXPECT_EQ(expected, sol.sortArray(nums));

  exit(EXIT_SUCCESS);
}
