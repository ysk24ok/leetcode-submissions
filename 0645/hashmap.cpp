#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    unordered_map<int, size_t> counts;
    for (const int& num : nums) {
      counts[num]++;
    }
    vector<int> ret(2);
    for (size_t i = 1; i <= nums.size(); ++i) {
      if (counts.find(i) == counts.end()) {
        ret[1] = i;
      } else if (counts[i] == 2) {
        ret[0] = i;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums, expected;

  nums = {1, 2, 2, 4}, expected = {2, 3};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 1}, expected = {1, 2};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 1, 2, 4}, expected = {1, 3};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 2, 3, 3}, expected = {3, 4};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 2, 2, 3}, expected = {2, 4};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {2, 2}, expected = {2, 1};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  nums = {1, 3, 3}, expected = {3, 2};
  EXPECT_EQ(expected, sol.findErrorNums(nums));

  exit(EXIT_SUCCESS);
}
