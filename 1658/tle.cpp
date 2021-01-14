#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    min_operations_ = numeric_limits<int>::max();
    unordered_map<int, unordered_map<int, int>> memo;
    dfs(nums, x, memo, 0, nums.size()-1, 0);
    return min_operations_ < numeric_limits<int>::max() ? min_operations_ : -1;
  }

  void dfs(const vector<int>& nums, int x,
          unordered_map<int, unordered_map<int, int>>& memo,
          int left_idx, int right_idx, int operations) {
    if (x == 0) {
      min_operations_ = min(operations, min_operations_);
      return;
    } else if (x < 0) {
      return;
    }
    if (right_idx + 1 == left_idx) {
      return;
    }
    if (memo.find(left_idx) != memo.end() && memo[left_idx].find(right_idx) != memo[left_idx].end()) {
      return;
    }
    memo[left_idx][right_idx] = 0;
    dfs(nums, x - nums[left_idx], memo, left_idx + 1, right_idx, operations + 1);
    dfs(nums, x - nums[right_idx], memo, left_idx, right_idx - 1, operations + 1);
  }

 private:
  int min_operations_;
};

int main() {
  Solution sol;
  vector<int> nums;
  int x, expected;

  nums = {1, 1, 4, 2, 3}, x = 5, expected = 2;
  EXPECT_EQ(expected, sol.minOperations(nums, x));

  nums = {5, 6, 7, 8, 9}, x = 4, expected = -1;
  EXPECT_EQ(expected, sol.minOperations(nums, x));

  nums = {3, 2, 20, 1, 1, 3}, x = 10, expected = 5;
  EXPECT_EQ(expected, sol.minOperations(nums, x));

  nums = {1, 2, 3, 4, 5}, x = 15, expected = 5;
  EXPECT_EQ(expected, sol.minOperations(nums, x));

  exit(EXIT_SUCCESS);
}
