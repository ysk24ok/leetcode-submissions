#include <gtest/gtest.h>

#include <vector>
#include <utility>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
  }

  int quickSelect(vector<int>& nums, size_t low, size_t high, int target) {
    // nums = {2,4,1,5,3} => {2,1,4,5,3}
    size_t pivot = low;
    int pivot_val = nums[high];
    for (size_t i = low; i < high; ++i) {
      if (nums[i] <= pivot_val) {
        swap(nums[pivot++], nums[i]);
      }
    }
    // nums = {2,1,4,5,3} => {2,1,3,5,4}
    swap(nums[pivot], nums[high]);
    if (pivot > target) {
      return quickSelect(nums, low, pivot - 1, target);
    } else if (pivot < target) {
      return quickSelect(nums, pivot + 1, high, target);
    } else {
      return nums[target];
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int k, expected;

  nums = {3, 2, 1, 5, 6, 4}, k = 2, expected = 5;
  EXPECT_EQ(expected, sol.findKthLargest(nums, k));

  nums = {3, 2, 3, 1, 2, 4, 5, 5, 6}, k = 4, expected = 4;
  EXPECT_EQ(expected, sol.findKthLargest(nums, k));

  exit(EXIT_SUCCESS);
}
