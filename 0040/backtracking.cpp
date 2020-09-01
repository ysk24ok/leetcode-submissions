#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
      if (i > begin && candidates[i-1] == candidate) continue;
      sol.push_back(candidate);
      if (candidate == target) {
        ret.push_back(sol);
      } else {
        recursion(candidates, target - candidate, i+1, ret, sol);
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

  candidates = {10,1,2,7,6,1,5};
  target = 8;
  expected = {
    {1,1,6},
    {1,2,5},
    {1,7},
    {2,6}
  };
  got = sol.combinationSum2(candidates, target);
  EXPECT_EQ(expected, got);

  candidates = {2,5,2,1,2};
  target = 5;
  expected = {
    {1,2,2},
    {5}
  };
  got = sol.combinationSum2(candidates, target);
  EXPECT_EQ(expected, got);
}
