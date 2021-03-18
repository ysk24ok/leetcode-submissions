#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    const size_t n = nums.size();
    if (n < 2) return n;
    vector<int> up(n, 1);
    vector<int> down(n, 1);
    for (size_t i = 1; i < n; ++i) {
      if (nums[i] > nums[i-1]) {  // up
        up[i] = down[i-1] + 1;
        down[i] = down[i-1];
      } else if (nums[i] < nums[i-1]) { // down
        down[i] = up[i-1] + 1;
        up[i] = up[i-1];
      } else {
        up[i] = up[i-1];
        down[i] = down[i-1];
      }
    }
    return max(up[n-1], down[n-1]);
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {1, 7, 4, 9, 2, 5}, expected = 6;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));

  nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8}, expected = 7;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));

  nums = {1, 2, 3, 4, 5, 6, 7, 8, 9}, expected = 2;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));

  nums = {1}, expected = 1;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));

  nums = {1, 2}, expected = 2;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));

  nums = {1, 1}, expected = 1;
  EXPECT_EQ(expected, sol.wiggleMaxLength(nums));
}
