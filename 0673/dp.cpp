#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    const size_t n = nums.size();
    int longest = 1;
    vector<int> lengths(n, 1);
    vector<int> counts(n, 1);
    for (size_t i = 1; i < n; ++i) {
      for (size_t j = 0; j < i; ++j) {
        if (nums[j] >= nums[i]) {
          continue;
        }
        int new_len = lengths[j] + 1;
        if (new_len == lengths[i]) {
          counts[i] += counts[j];
        } else if (new_len > lengths[i]) {
          lengths[i] = new_len;
          counts[i] = counts[j];
        }
      }
      longest = max(longest, lengths[i]);
    }
    int ret = 0;
    for (size_t i = 0; i < n; ++i) {
      if (lengths[i] == longest) {
        ret += counts[i];
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {1, 3, 5, 4, 7};
  expected = 2;
  EXPECT_EQ(expected, sol.findNumberOfLIS(nums));

  nums = {2, 2, 2, 2, 2};
  expected = 5;
  EXPECT_EQ(expected, sol.findNumberOfLIS(nums));

  nums = {};
  expected = 0;
  EXPECT_EQ(expected, sol.findNumberOfLIS(nums));

  nums = {1};
  expected = 1;
  EXPECT_EQ(expected, sol.findNumberOfLIS(nums));

  nums = {1, 2, 4, 3, 5, 4, 7, 2};
  expected = 3;
  EXPECT_EQ(expected, sol.findNumberOfLIS(nums));

  exit(EXIT_SUCCESS);
}
