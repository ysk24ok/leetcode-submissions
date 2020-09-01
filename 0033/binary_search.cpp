#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int ret = -1;
    while (left <= right) {
      int mid = (right - left) / 2 + left;
      if (nums[mid] == target) {
        ret = mid;
        break;
      }
      // pivot is in the right half
      if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && target <= nums[mid]) { right = mid - 1; }
        else { left = mid + 1; }
      // pivot is in the left half
      } else {
        if (nums[mid] <= target && target <= nums[right]) { left = mid + 1; }
        else { right = mid - 1; }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {4,5,6,7,0,1,2};
  EXPECT_EQ(0, sol.search(nums, 4));
  EXPECT_EQ(1, sol.search(nums, 5));
  EXPECT_EQ(2, sol.search(nums, 6));
  EXPECT_EQ(3, sol.search(nums, 7));
  EXPECT_EQ(4, sol.search(nums, 0));
  EXPECT_EQ(5, sol.search(nums, 1));
  EXPECT_EQ(6, sol.search(nums, 2));
  EXPECT_EQ(-1, sol.search(nums, 3));

  nums = {5,6,0,1,2,3};
  EXPECT_EQ(-1, sol.search(nums, 4));
  EXPECT_EQ(0, sol.search(nums, 5));
  EXPECT_EQ(1, sol.search(nums, 6));
  EXPECT_EQ(2, sol.search(nums, 0));
  EXPECT_EQ(3, sol.search(nums, 1));
  EXPECT_EQ(4, sol.search(nums, 2));
  EXPECT_EQ(5, sol.search(nums, 3));

  nums = {3,1};
  EXPECT_EQ(1, sol.search(nums, 1));
}
