#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    size_t red = 0, white = 0, blue = nums.size();
    while (white < blue) {
      // red
      if (nums[white] == 0) {
        int tmp = nums[white];
        nums[white] = nums[red];
        nums[red] = tmp;
        red++;
        white++;
      // white
      } else if (nums[white] == 1) {
        white++;
      // blue
      } else {
        int tmp = nums[white];
        nums[white] = nums[blue-1];
        nums[blue-1] = tmp;
        blue--;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  vector<int> expected;

  nums = {2,0,2,1,1,0};
  expected = {0,0,1,1,2,2};
  sol.sortColors(nums);
  EXPECT_EQ(expected, nums);

  nums = {2};
  expected = {2};
  sol.sortColors(nums);
  EXPECT_EQ(expected, nums);

  exit(EXIT_SUCCESS);
}
