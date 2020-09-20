#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    const size_t m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ret = 0;
    int num_non_obstacles = 0;
    size_t start_i, start_j;
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          num_non_obstacles++;
        } else if (grid[i][j] == 1) {
          start_i = i;
          start_j = j;
        }
      }
    }
    recursion(grid, visited, start_i, start_j, num_non_obstacles, 0, ret);
    return ret;
  }

 private:
  void recursion(const vector<vector<int>>& grid, vector<vector<bool>>& visited, size_t i, size_t j,
                 const int total_num_non_obstacles, int num_non_obstacles, int& ret) {
    if (grid[i][j] == -1 || visited[i][j]) { return; }
    if (grid[i][j] == 2) {
      if (num_non_obstacles == total_num_non_obstacles) {
        ret++;
      }
      return;
    }
    if (grid[i][j] == 0) { num_non_obstacles++; }
    visited[i][j] = true;
    if (i > 0) { recursion(grid, visited, i - 1, j, total_num_non_obstacles, num_non_obstacles, ret); }
    if (j > 0) { recursion(grid, visited, i, j - 1, total_num_non_obstacles, num_non_obstacles, ret); }
    if (i < grid.size() - 1) { recursion(grid, visited, i + 1, j, total_num_non_obstacles, num_non_obstacles, ret); }
    if (j < grid[0].size() - 1) { recursion(grid, visited, i, j + 1, total_num_non_obstacles, num_non_obstacles, ret); }
    visited[i][j] = false;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> grid;
  int expected;

  grid = {
    {1,0,0,0},
    {0,0,0,0},
    {0,0,2,-1}
  };
  expected = 2;
  EXPECT_EQ(expected, sol.uniquePathsIII(grid));

  grid = {
    {1,0,0,0},
    {0,0,0,0},
    {0,0,0,2}
  };
  expected = 4;
  EXPECT_EQ(expected, sol.uniquePathsIII(grid));

  grid = {
    {0,1},
    {2,0},
  };
  expected = 0;
  EXPECT_EQ(expected, sol.uniquePathsIII(grid));

  exit(EXIT_SUCCESS);
}
