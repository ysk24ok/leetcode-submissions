#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    recursion(nums, 0, nums.size(), res);
    return res;
  }

 private:
  void recursion(vector<int> nums, int start, int end, vector<vector<int>> &res) {
    if (start == end-1) {
      res.push_back(nums);
      return;
    }
    for (int i = start; i < end; i++) {
      // do recursion only the first tiem to avoid duplicates
      if (start != i && nums[start] == nums[i]) {
        continue;
      }
      swap(nums[start], nums[i]);
      recursion(nums, start+1, end, res);
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  vector<vector<int>> got, expected;

  nums = {1,2,1};
  expected = {
    {1,1,2},
    {1,2,1},
    {2,1,1}
  };
  EXPECT_EQ(expected, sol.permuteUnique(nums));

  nums = {1,2};
  expected = {
    {1,2},
    {2,1}
  };
  EXPECT_EQ(expected, sol.permuteUnique(nums));

  nums = {1,2,3};
  expected = {
    {1,2,3},
    {1,3,2},
    {2,1,3},
    {2,3,1},
    {3,1,2},
    {3,2,1},
  };
  EXPECT_EQ(expected, sol.permuteUnique(nums));

  nums = {1,1,2,2};
  expected = {
    {1,1,2,2},
    {1,2,1,2},
    {1,2,2,1},
    {2,1,1,2},
    {2,1,2,1},
    {2,2,1,1}
  };
  EXPECT_EQ(expected, sol.permuteUnique(nums));

  exit(EXIT_SUCCESS);
}
