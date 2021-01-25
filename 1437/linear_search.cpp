#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool kLengthApart(vector<int>& nums, int k) {
    size_t prev_idx = 0;
    while (prev_idx < nums.size() && nums[prev_idx] == 0) {
      prev_idx++;
    }
    for (size_t i = prev_idx + 1; i < nums.size(); ++i) {
      if (nums[i] == 0) { continue; }
      if ((i - prev_idx - 1) < k) {
        return false;
      }
      prev_idx = i;
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int k;
  bool expected;

  nums = {1, 0, 0, 0, 1, 0, 0, 1}, k = 2, expected = true;
  EXPECT_EQ(expected, sol.kLengthApart(nums, k));

  nums = {1, 0, 0, 1, 0, 1}, k = 2, expected = false;
  EXPECT_EQ(expected, sol.kLengthApart(nums, k));

  nums = {1, 1, 1, 1, 1}, k = 0, expected = true;
  EXPECT_EQ(expected, sol.kLengthApart(nums, k));

  nums = {0, 1, 0, 1}, k = 1, expected = true;
  EXPECT_EQ(expected, sol.kLengthApart(nums, k));

  nums = {0, 0, 0, 0}, k = 2, expected = true;
  EXPECT_EQ(expected, sol.kLengthApart(nums, k));

  exit(EXIT_SUCCESS);
}
