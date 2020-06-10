#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left < right) {
      mid = (right - left) / 2 + left;
      if (target > nums[mid]) {
        left = mid + 1;
      } else if (target < nums[mid]) {
        right = mid;
      } else {
        return mid;
      }
    }
    while (mid < nums.size() && nums[mid] < target) { mid++; }
    return mid;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {1,3,5,6};
  EXPECT_EQ(0, sol.searchInsert(nums, 0));
  EXPECT_EQ(0, sol.searchInsert(nums, 1));
  EXPECT_EQ(1, sol.searchInsert(nums, 2));
  EXPECT_EQ(1, sol.searchInsert(nums, 3));
  EXPECT_EQ(2, sol.searchInsert(nums, 4));
  EXPECT_EQ(2, sol.searchInsert(nums, 5));
  EXPECT_EQ(4, sol.searchInsert(nums, 7));

  nums = {};
  EXPECT_EQ(0, sol.searchInsert(nums, 1));

  nums = {1};
  EXPECT_EQ(0, sol.searchInsert(nums, 0));
  EXPECT_EQ(0, sol.searchInsert(nums, 1));
  EXPECT_EQ(1, sol.searchInsert(nums, 2));

  exit(EXIT_SUCCESS);
}
