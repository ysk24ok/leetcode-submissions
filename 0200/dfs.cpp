#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) return 0;
    int ret = 0;
    for (int i = 0, m = grid.size(); i < m; i++) {
      for (int j = 0, n = grid[0].size(); j < n; j++) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ret++;
        }
      }
    }
    return ret;
  }

  void dfs(vector<vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
    if (grid[i][j] != '1') return;
    grid[i][j] = '-';
    dfs(grid, i-1, j);
    dfs(grid, i+1, j);
    dfs(grid, i, j-1);
    dfs(grid, i, j+1);
  }
};

int main() {
  Solution sol;
  vector<vector<char>> grid;

  grid = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}
  };
  assert(sol.numIslands(grid) == 1);

  grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
  };
  assert(sol.numIslands(grid) == 3);

  grid = {};
  assert(sol.numIslands(grid) == 0);

  grid = {
    {'1','0','0','1','0'},
  };
  assert(sol.numIslands(grid) == 2);
}
