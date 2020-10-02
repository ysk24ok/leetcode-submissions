#include <gtest/gtest.h>

#include <cstdlib>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    if (candidates.size() == 0) {return ret; }
    sort(candidates.begin(), candidates.end());
    queue<pair<vector<int>, size_t>> q;
    q.push({{}, 0});
    while (!q.empty()) {
      pair<vector<int>, size_t> elem = q.front();
      q.pop();
      for (size_t i = elem.second; i < candidates.size(); ++i) {
        vector<int> new_combination = elem.first;
        int new_total = accumulate(new_combination.begin(), new_combination.end(), 0) + candidates[i];
        if (new_total < target) {
          new_combination.push_back(candidates[i]);
          q.push({new_combination, i});
        } else if (new_total > target) {
          break;
        } else {  // new_total == target
          new_combination.push_back(candidates[i]);
          ret.push_back(new_combination);
          break;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> candidates;
  int target;
  vector<vector<int>> expected;

  candidates = {2,3,6,7};
  target = 7;
  expected = {
    {7},
    {2,2,3},
  };
  EXPECT_EQ(expected, sol.combinationSum(candidates, target));

  candidates = {2,3,5};
  target = 8;
  expected = {
    {3,5},
    {2,3,3},
    {2,2,2,2},
  };
  EXPECT_EQ(expected, sol.combinationSum(candidates, target));
}
