#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> d = {
  {1,1},{1,0},{0,1},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}
};

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;
    size_t m = grid.size(), n = grid[0].size();
    queue<tuple<size_t, size_t, int>> q;
    q.push(make_tuple(0, 0, 1));
    int ret = -1;
    while (!q.empty()) {
      tuple<size_t, size_t, int> t = q.front();
      q.pop();
      size_t i = get<0>(t), j = get<1>(t);
      int len = get<2>(t);
      if (grid[i][j] == 1) continue;
      if (i == m - 1 && j == n - 1) {
        ret = len;
        break;
      }
      grid[i][j] = 1;
      for (auto& vec : d) {
        int new_i = i + vec[0];
        int new_j = j + vec[1];
        if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) continue;
        q.push(make_tuple(new_i, new_j, len+1));
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> grid;

  grid = {
    {0,1},
    {1,0}
  };
  assert(sol.shortestPathBinaryMatrix(grid) == 2);

  grid = {
    {0,0,0},
    {1,1,0},
    {1,1,0}
  };
  assert(sol.shortestPathBinaryMatrix(grid) == 4);

  grid = {
    {0,1,1,0,0,1},
    {1,0,1,0,1,0},
    {1,0,1,0,1,0},
    {1,0,0,0,1,0},
    {1,1,0,1,1,0},
    {1,1,1,0,0,0},
  };
  assert(sol.shortestPathBinaryMatrix(grid) == 8);

  grid = {
    {1,0,0},
    {1,1,0},
    {1,1,0}
  };
  assert(sol.shortestPathBinaryMatrix(grid) == -1);

  grid = {
    {0,0},
    {0,1}
  };
  assert(sol.shortestPathBinaryMatrix(grid) == -1);
}
