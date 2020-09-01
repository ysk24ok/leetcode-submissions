#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ret;
    vector<int> sol;
    recursion(candidates, target, 0, ret, sol);
    return ret;
  }

  void recursion(const vector<int>& candidates, int target, int begin,
                 vector<vector<int>>& ret, vector<int>& sol) {
    for (size_t i = begin; i < candidates.size(); i++) {
      const int& candidate = candidates[i];
      if (candidate > target) continue;
      sol.push_back(candidate);
      if (candidate == target) {
        ret.push_back(sol);
      } else {
        recursion(candidates, target - candidate, i, ret, sol);
      }
      sol.pop_back();
    }
  }
};

int main() {
  Solution sol;
  vector<int> candidates;
  int target;
  vector<vector<int>> got, expected;

  candidates = {2,3,6,7};
  target = 7;
  expected = {
    {2,2,3},
    {7}
  };
  got = sol.combinationSum(candidates, target);
  EXPECT_EQ(expected, got);

  candidates = {2,3,5};
  target = 8;
  expected = {
    {2,2,2,2},
    {2,3,3},
    {3,5}
  };
  got = sol.combinationSum(candidates, target);
  EXPECT_EQ(expected, got);
}
