// memory complexity: O(m * n)
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    size_t m = obstacleGrid.size();
    size_t n = obstacleGrid[0].size();
    vector<vector<int64_t>> num_paths(m);
    for (size_t i = 0; i < m; i++) {
      num_paths[i].resize(n);
    }
    num_paths[0][0] = (obstacleGrid[0][0] != 1) ? 1 : 0;
    for (size_t i = 1; i < m; i++) {
      if (obstacleGrid[i][0] != 1) {
        num_paths[i][0] = num_paths[i-1][0];
      } else {
        num_paths[i][0] = 0;
      }
    }
    for (int j = 1; j < n; j++) {
      if (obstacleGrid[0][j] != 1) {
        num_paths[0][j] = num_paths[0][j-1];
      } else {
        num_paths[0][j] = 0;
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] != 1) {
          num_paths[i][j] = num_paths[i-1][j] + num_paths[i][j-1];
        } else {
          num_paths[i][j] = 0;
        }
      }
    }
    return num_paths[m-1][n-1];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> d;

  d = {
    {1},
  };
  assert(sol.uniquePathsWithObstacles(d) == 0);

  d = {
    {0,1,0},
    {0,0,0}
  };
  assert(sol.uniquePathsWithObstacles(d) == 1);

  d = {
    {0,0},
    {1,0},
    {0,0}
  };
  assert(sol.uniquePathsWithObstacles(d) == 1);

  d = {
    {0,0,0},
    {0,1,0},
    {0,0,0}
  };
  assert(sol.uniquePathsWithObstacles(d) == 2);
}
