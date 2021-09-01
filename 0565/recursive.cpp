#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    const size_t n = nums.size();
    vector<bool> visited(n);
    int ret = 0;
    for (size_t i = 0; i < n; ++i) {
      ret = max(recursion(nums, i, visited, 0), ret);
    }
    return ret;
  }

  int recursion(const vector<int>& nums, size_t i, vector<bool>& visited, int cur_length) {
    if (visited[i]) {
      return cur_length;
    }
    visited[i] = true;
    return recursion(nums, nums[i], visited, cur_length + 1);
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {5, 4, 0, 3, 1, 6, 2}, expected = 4;
  EXPECT_EQ(expected, sol.arrayNesting(nums));

  nums = {0, 1, 2}, expected = 1;
  EXPECT_EQ(expected, sol.arrayNesting(nums));

  exit(EXIT_SUCCESS);
}
