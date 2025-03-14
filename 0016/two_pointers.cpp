#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    size_t j, k;
    int closest = nums[0] + nums[1] + nums[2];
    for (size_t i = 0; i < nums.size() - 2; i++) {
      j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (abs(sum - target) < abs(closest - target)) {
          closest = sum;
        }
        if (sum > target) { k--; }
        else { j++; }
       }
    }
    return closest;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int target;
  int expected;

  nums = {-1, 2, 1, -4}, target = 1, expected = 2;
  EXPECT_EQ(sol.threeSumClosest(nums, target), expected);

  nums = {0, 0, 0}, target = 1, expected = 0;
  EXPECT_EQ(sol.threeSumClosest(nums, target), expected);

  nums = {1, 1, 1, 1}, target = -100, expected = 3;
  EXPECT_EQ(sol.threeSumClosest(nums, target), expected);

  exit(EXIT_SUCCESS);
}
