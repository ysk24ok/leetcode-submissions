#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int up = 1, down = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i-1]) {
        up = down + 1;
      } else if (nums[i] < nums[i-1]) {
        down = up + 1;
      }
    }
    return max(up, down);
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  // nums: {1, 7, 4, 9, 2, 5}
  // up:   {1, 2, 2, 4, 4, 6}
  // down: {1, 1, 3, 3, 5, 5}
  nums = {1, 7, 4, 9, 2, 5}, expected = 6;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));

  nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8}, expected = 7;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));

  nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}, expected = 2;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));

  // nums: {1, 2, 3, 4, 5, 6}
  // up:   {1, 2, 2, 2, 2, 2}
  // down: {1, 1, 1, 1, 1, 1}
  nums = {1, 2, 3, 4, 5, 6}, expected = 2;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));

  exit(EXIT_SUCCESS);
}
