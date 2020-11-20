#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    if (nums.size() == 0) { return false; }
    int left = 0, right = nums.size() - 1;
    while (left + 1 < right) {
      int mid = (right - left) / 2 + left;
      if (nums[mid] == target) { return true; }
      // the left half is sorted
      if (nums[left] < nums[mid]) {
        if (nums[left] <= target && target < nums[mid]) {
          right = mid;
        } else {
          left = mid;
        }
      // the right half is sorted
      } else if (nums[mid] < nums[right]) {
        if (nums[mid] < target && target <= nums[right]) {
          left = mid;
        } else {
          right = mid;
        }
      } else {
        if (nums[left] == nums[mid]) { left++; }
        if (nums[mid] == nums[right]) { right--; }
      }
    }
    return nums[left] == target || nums[right] == target;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int target;

  nums = {2, 5, 6, 0, 0, 1, 2};
  target = 0;
  EXPECT_TRUE(sol.search(nums, target));
  target = 1;
  EXPECT_TRUE(sol.search(nums, target));
  target = 2;
  EXPECT_TRUE(sol.search(nums, target));
  target = 3;
  EXPECT_FALSE(sol.search(nums, target));
  target = 4;
  EXPECT_FALSE(sol.search(nums, target));
  target = 5;
  EXPECT_TRUE(sol.search(nums, target));
  target = 6;
  EXPECT_TRUE(sol.search(nums, target));
  target = 7;
  EXPECT_FALSE(sol.search(nums, target));

  nums = {}, target = 5;
  EXPECT_FALSE(sol.search(nums, target));

  exit(EXIT_SUCCESS);
}
