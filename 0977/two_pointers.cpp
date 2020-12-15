#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ret(nums.size());
    size_t idx = ret.size() - 1;
    size_t lp = 0, rp = nums.size() - 1;
    while (lp != rp) {
      int l_squared_val = nums[lp] * nums[lp];
      int r_squared_val = nums[rp] * nums[rp];
      if (l_squared_val >= r_squared_val) {
        ret[idx] = l_squared_val;
        lp++;
      } else {
        ret[idx] = r_squared_val;
        rp--;
      }
      idx--;
    }
    ret[idx] = nums[lp] * nums[lp];
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums, expected;

  nums = {-4, -1, 0, 3, 10}, expected = {0, 1, 9, 16, 100};
  EXPECT_EQ(expected, sol.sortedSquares(nums));

  nums = {-7, -3, 2, 3, 11}, expected = {4, 9, 9, 49, 121};
  EXPECT_EQ(expected, sol.sortedSquares(nums));

  exit(EXIT_SUCCESS);
}
