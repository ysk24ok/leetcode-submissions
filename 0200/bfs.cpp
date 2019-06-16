#include <cassert>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          bfs(grid, i, j);
          count++;
        }
      }
    }
    return count;
  }

  void bfs(vector<vector<char>>& grid, int i, int j) {
    int n = grid[0].size();
    queue<int> q;
    q.push(i * n + j);
    while (q.size() > 0) {
      int v = q.front();
      q.pop();
      int j = v % n;
      int i = (v - j) / n;
      if (i > 0 and grid[i-1][j] == '1') {
        q.push((i - 1) * n + j);
        grid[i-1][j] = '0';
      }
      if (j > 0 and grid[i][j-1] == '1') {
        q.push(i * n + j - 1);
        grid[i][j-1] = '0';
      }
      if (i + 1 < grid.size() and grid[i+1][j] == '1') {
        q.push((i + 1) * n + j);
        grid[i+1][j] = '0';
      }
      if (j + 1 < grid[i].size() and grid[i][j+1] == '1') {
        q.push(i * n + j + 1);
        grid[i][j+1] = '0';
      }
    }
  }
};

int main() {
  vector<vector<char>> grid;
  int got;
  Solution* sol = new Solution();

  grid = {
    {'1', '1', '1', '1', '0'},
    {'1', '1', '0', '1', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '0', '0', '0'}
  };
  got = sol->numIslands(grid);
  assert(got == 1);

  grid = {
    {'1', '1', '0', '0', '0'},
    {'1', '1', '0', '0', '0'},
    {'0', '0', '1', '0', '0'},
    {'0', '0', '0', '1', '1'}
  };
  got = sol->numIslands(grid);
  assert(got == 3);

  grid = {
      {'1', '1', '1'},
      {'0', '1', '0'},
      {'1', '1', '1'}
  };
  got = sol->numIslands(grid);
  assert(got == 1);

  delete sol;
}
