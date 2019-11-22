#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    size_t m = grid.size(), n = grid[0].size();
    vector<vector<bool>> checked(m, vector<bool>(n, false));
    int ret = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (checked[i][j]) continue;
        if (grid[i][j] == 1) {
          checked[i][j] = true;
          continue;
        }
        if (dfs(grid, i, j, checked)) {
          ret++;
        }
      }
    }
    return ret;
  }

  bool dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& checked) {
    size_t m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) return false;
    if (checked[i][j]) return true;
    checked[i][j] = true;
    if (grid[i][j] == 1) return true;
    bool b1 = dfs(grid, i+1, j, checked);
    bool b2 = dfs(grid, i-1, j, checked);
    bool b3 = dfs(grid, i, j+1, checked);
    bool b4 = dfs(grid, i, j-1, checked);
    return (b1 && b2 && b3 && b4) ? true : false;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> grid;

  grid = {
    {1,1,1,1,1,1,1,0},
    {1,0,0,0,0,1,1,0},
    {1,0,1,0,1,1,1,0},
    {1,0,0,0,0,1,0,1},
    {1,1,1,1,1,1,1,0}
  };
  assert(sol.closedIsland(grid) == 2);

  grid = {
    {0,0,1,0,0},
    {0,1,0,1,0},
    {0,1,1,1,0}
  };
  assert(sol.closedIsland(grid) == 1);

  grid = {
    {1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1},
    {1,0,1,1,1,0,1},
    {1,0,1,0,1,0,1},
    {1,0,1,1,1,0,1},
    {1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1}
  };
  assert(sol.closedIsland(grid) == 2);

  grid = {
    {0,0,1,1,0,1,0,0,1,0},
    {1,1,0,1,1,0,1,1,1,0},
    {1,0,1,1,1,0,0,1,1,0},
    {0,1,1,0,0,0,0,1,0,1},
    {0,0,0,0,0,0,1,1,1,0},
    {0,1,0,1,0,1,0,1,1,1},
    {1,0,1,0,1,1,0,0,0,1},
    {1,1,1,1,1,1,0,0,0,0},
    {1,1,1,0,0,1,0,1,0,1},
    {1,1,1,0,1,1,0,1,1,0}
  };
  assert(sol.closedIsland(grid) == 5);
}
