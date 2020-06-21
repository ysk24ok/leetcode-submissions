#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if (dungeon.size() == 0) { return 1; }
    vector<vector<int>> memo(dungeon.size(), vector<int>(dungeon[0].size(), -1));
    return recursion(dungeon, memo, 0, 0);
  }

  int recursion(const vector<vector<int>>& dungeon, vector<vector<int>>& memo, size_t i, size_t j) {
    const size_t m = dungeon.size(), n = dungeon[0].size();
    if (i >= m || j >= n) { return numeric_limits<int>::max(); }
    if (i == m - 1 && j == n - 1) {
      memo[i][j] = dungeon[i][j] < 0 ? 1 - dungeon[i][j] : 1;
      return memo[i][j];
    }
    if (memo[i][j] != -1) { return memo[i][j]; }
    int right = recursion(dungeon, memo, i+1, j);
    int down = recursion(dungeon, memo, i, j+1);
    memo[i][j] = min(right, down) - dungeon[i][j];
    if (memo[i][j] <= 0) { memo[i][j] = 1; }
    return memo[i][j];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> dungeon;
  int expected;

  dungeon = {
    {-2,-3,3},
    {-5,-10,1},
    {10,30,-5},
  };
  expected = 7;
  EXPECT_EQ(expected, sol.calculateMinimumHP(dungeon));

  dungeon = {
    {0,0,0},
    {1,1,-1},
  };
  expected = 1;
  EXPECT_EQ(expected, sol.calculateMinimumHP(dungeon));

  exit(EXIT_SUCCESS);
}
