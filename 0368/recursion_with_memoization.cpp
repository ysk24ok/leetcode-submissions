#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"
#include "leetcode/assert.hpp"

using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    unordered_map<size_t, vector<int>> memo;
    sort(nums.begin(), nums.end());
    return recursion(memo, nums, 0);
  }

  vector<int> recursion(unordered_map<size_t, vector<int>>& memo, const vector<int>& nums, size_t idx) {
    if (idx >= nums.size()) { return {}; }
    if (memo.find(idx) != memo.end()) { return memo[idx]; }
    int div = idx != 0 ? nums[idx-1] : 1;
    vector<int> maxret;
    vector<int> ret;
    for (int jdx = idx; jdx < nums.size(); ++jdx) {
      if (nums[jdx] % div != 0) { continue; }
      ret = recursion(memo, nums, jdx+1);
      ret.insert(ret.begin(), nums[jdx]);
      if (ret.size() > maxret.size()) { maxret = ret; }
    }
    memo[idx] = maxret;
    return maxret;
  }
};

int main() {
  Solution sol;
  vector<int> nums, expected;

  nums = {1,2,3};
  expected = {1,2};
  EXPECT_EQ(expected, sol.largestDivisibleSubset(nums));

  nums = {1,2,4,8};
  expected = {1,2,4,8};
  EXPECT_EQ(expected, sol.largestDivisibleSubset(nums));

  nums = {2,3,9};
  expected = {3,9};
  EXPECT_EQ(expected, sol.largestDivisibleSubset(nums));

  exit(EXIT_SUCCESS);
}
