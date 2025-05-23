#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (const auto& num : nums) ret ^= num;
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {2,2,1}, expected = 1;
  EXPECT_EQ(sol.singleNumber(nums), expected);

  nums = {4,1,2,1,2}, expected = 4;
  EXPECT_EQ(sol.singleNumber(nums), expected);

  nums = {2}, expected = 2;
  EXPECT_EQ(sol.singleNumber(nums), expected);
}
