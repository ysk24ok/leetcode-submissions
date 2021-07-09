#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

// time complexity: O(N^2)
// space complexity: O(N)
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> length(nums.size(), 1);
    int ret = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (nums[j] >= nums[i]) {
          continue;
        }
        length[i] = max(length[j] + 1, length[i]);
      }
      ret = max(length[i], ret);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {10, 9, 2, 5, 3, 7, 101, 18};
  expected = 4;
  EXPECT_EQ(expected, sol.lengthOfLIS(nums));

  nums = {0};
  expected = 1;
  EXPECT_EQ(expected, sol.lengthOfLIS(nums));

  nums = {5, 4, 3, 2, 1};
  expected = 1;
  EXPECT_EQ(expected, sol.lengthOfLIS(nums));

  nums = {6, 7, 8, 9, 1, 1, 2, 3, 4, 5};
  expected = 5;
  EXPECT_EQ(expected, sol.lengthOfLIS(nums));
}
