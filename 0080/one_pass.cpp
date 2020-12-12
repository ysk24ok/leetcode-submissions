#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) { return nums.size(); }
    int curr_len = 1;
    size_t i = 0;
    while (i + 1 < nums.size()) {
      if (nums[i] == nums[i+1]) {
        if (curr_len <= 1) {
          ++i;
          ++curr_len;
        } else {
          nums.erase(nums.begin() + i + 1);
        }
      } else {
        ++i;
        curr_len = 1;
      }
    }
    return nums.size();
  }
};

int main() {
  Solution sol;
  vector<int> nums, expected_nums;
  int expected;

  nums = {1, 1, 1, 2, 2, 3};
  expected_nums = {1, 1, 2, 2, 3};
  expected = 5;
  EXPECT_EQ(expected, sol.removeDuplicates(nums));
  EXPECT_EQ(expected_nums, nums);

  nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  expected_nums = {0, 0, 1, 1, 2, 3, 3};
  expected = 7;
  EXPECT_EQ(expected, sol.removeDuplicates(nums));
  EXPECT_EQ(expected_nums, nums);

  nums = {};
  expected_nums = {};
  expected = 0;
  EXPECT_EQ(expected, sol.removeDuplicates(nums));
  EXPECT_EQ(expected_nums, nums);

  nums = {1};
  expected_nums = {1};
  expected = 1;
  EXPECT_EQ(expected, sol.removeDuplicates(nums));
  EXPECT_EQ(expected_nums, nums);

  nums = {1, 1};
  expected_nums = {1, 1};
  expected = 2;
  EXPECT_EQ(expected, sol.removeDuplicates(nums));
  EXPECT_EQ(expected_nums, nums);

  exit(EXIT_SUCCESS);
}
