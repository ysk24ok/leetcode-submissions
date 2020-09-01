#include <cassert>
#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    const size_t m = nums.size();
    vector<int> temp(m);
    mergeSort(nums, temp, 0, m-1);
    return nums;
  }

 private:
  void mergeSort(vector<int>& nums, vector<int>& temp, size_t left, size_t right) {
    if (left == right) {
      return;
    }
    size_t mid = (right - left) / 2 + left;
    mergeSort(nums, temp, left, mid);
    mergeSort(nums, temp, mid+1, right);
    merge(nums, temp, left, mid, mid+1, right);
  }

  void merge(vector<int>& nums, vector<int>& temp,
             size_t left_start, size_t left_end, size_t right_start, size_t right_end) {
    size_t i = left_start, l = left_start, r = right_start;
    while (l <= left_end && r <= right_end) {
      if (nums[l] < nums[r]) {
        temp[i++] = nums[l++];
      } else {
        temp[i++] = nums[r++];
      }
    }
    while (l <= left_end) {
      temp[i++] = nums[l++];
    }
    while (r <= right_end) {
      temp[i++] = nums[r++];
    }
    for (size_t j = left_start; j <= right_end; ++j) {
      nums[j] = temp[j];
    }
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
