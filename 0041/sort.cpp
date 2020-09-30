#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ret = 1;
    for (const auto& num : nums) {
      if (num <= 0) {
        continue;
      }
      if (ret == num) {
        ret++;
      } else if (ret < num) {
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {1, 2, 0};
  expected = 3;
  EXPECT_EQ(expected, sol.firstMissingPositive(nums));

  nums = {3, 4, -1, 1};
  expected = 2;
  EXPECT_EQ(expected, sol.firstMissingPositive(nums));

  nums = {7, 8, 9, 11, 12};
  expected = 1;
  EXPECT_EQ(expected, sol.firstMissingPositive(nums));

  exit(EXIT_SUCCESS);
}
