#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      for (const int& num : nums) {
        sum += num >> i & 1;
      }
      sum %= 3;
      ret |= sum << i;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {2,2,3,2};
  expected = 3;
  EXPECT_EQ(expected, sol.singleNumber(nums));

  nums = {0,1,0,1,0,1,99};
  expected = 99;
  EXPECT_EQ(expected, sol.singleNumber(nums));

  //  1: 0...001
  // -1: 1...111
  nums = {-1,1,1,1};
  expected = -1;
  EXPECT_EQ(expected, sol.singleNumber(nums));

  nums = {-1,-1,1,-1};
  expected = 1;
  EXPECT_EQ(expected, sol.singleNumber(nums));

  // test case 8
  // -2: 1...110
  //  1: 0...001
  // -3: 1...101
  // -4: 1...100
  nums = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
  expected = -4;
  EXPECT_EQ(expected, sol.singleNumber(nums));

  // test case 9
  nums = {-19,-46,-19,-46,-9,-9,-19,17,17,17,-13,-13,-9,-13,-46,-28};
  expected = -28;
  EXPECT_EQ(expected, sol.singleNumber(nums));

  // test case 11
  nums = {-2,-2,1,1,4,1,4,4,-4,-2};
  expected = -4;
  EXPECT_EQ(expected, sol.singleNumber(nums));

  exit(EXIT_SUCCESS);
}
