#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    if (grid.size() == 1 && grid[0].size() == 1) return true;
    switch (grid[0][0]) {
      case 1:
        return recursion(grid, 0, 0, 0, 1);
      case 2:
        return recursion(grid, 0, 0, 1, 0);
      case 3:
        return recursion(grid, 0, 0, 1, 0);
      case 4:
        return recursion(grid, 0, 0, 1, 0) || recursion(grid, 0, 0, 0, 1);
      case 5:
        return false;
      case 6:
        return recursion(grid, 0, 0, 0, 1);
      default:
        return false;
    }
  }

  bool recursion(const vector<vector<int>>& grid, int prev_i, int prev_j, int diff_i, int diff_j) {
    int cur_i = prev_i + diff_i;
    int cur_j = prev_j + diff_j;
    if (cur_i >= grid.size() || cur_j >= grid[0].size()) return false;
    int cur_street = grid[cur_i][cur_j];
    int next_diff_i = 0;
    int next_diff_j = 0;
    // from above
    if (diff_i == 1 && diff_j == 0) {
      if (cur_street == 2)      { next_diff_i = 1; next_diff_j = 0; }
      else if (cur_street == 5) { next_diff_i = 0; next_diff_j = -1; }
      else if (cur_street == 6) { next_diff_i = 0; next_diff_j = 1; }
      else return false;
    // from below
    } else if (diff_i == -1 && diff_j == 0) {
      if (cur_street == 2)      { next_diff_i = -1; next_diff_j = 0; }
      else if (cur_street == 3) { next_diff_i = 0; next_diff_j = -1; }
      else if (cur_street == 4) { next_diff_i = 0; next_diff_j = 1; }
      else return false;
    // from left
    } else if (diff_i == 0 && diff_j == 1) {
      if (cur_street == 1)      { next_diff_i = 0; next_diff_j = 1; }
      else if (cur_street == 3) { next_diff_i = 1; next_diff_j = 0; }
      else if (cur_street == 5) { next_diff_i = -1; next_diff_j = 0; }
      else return false;
    // from right
    } else if (diff_i == 0 && diff_j == -1) {
      if (cur_street == 1)      { next_diff_i = 0; next_diff_j = -1; }
      else if (cur_street == 4) { next_diff_i = 1; next_diff_j = 0; }
      else if (cur_street == 6) { next_diff_i = -1; next_diff_j = 0; }
      else return false;
    // impossible
    } else {
      assert(false);
    }
    if (cur_i == grid.size()-1 && cur_j == grid[0].size()-1) return true;
    else return recursion(grid, cur_i, cur_j, next_diff_i, next_diff_j);
  }
};

int main() {
  Solution sol;
  vector<vector<int>> grid;

  grid = {{2,4,3},{6,5,2}};
  assert(sol.hasValidPath(grid));

  grid = {{1,2,1},{1,2,1}};
  assert(!sol.hasValidPath(grid));

  grid = {{1,1,2}};
  assert(!sol.hasValidPath(grid));

  grid = {{1,1,1,1,1,1,3}};
  assert(sol.hasValidPath(grid));

  grid = {{4,1},{6,1}};
  assert(sol.hasValidPath(grid));

  grid = {{4,3},{2,6}};
  assert(sol.hasValidPath(grid));

  grid = {{1}};
  assert(sol.hasValidPath(grid));
}
