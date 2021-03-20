#include "gtest/gtest.h"

#include <algorithm>
#include <cstdlib>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> ret(m, vector<int>(n, numeric_limits<int>::max()));
    queue<pair<int, int>> q;
    // First, push all 0 cells to the queue
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          q.push({i, j});
          ret[i][j] = 0;
        }
      }
    }
    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      int i = p.first;
      int j = p.second;
      for (auto& mov : moves) {
        int new_i = i + mov.first;
        int new_j = j + mov.second;
        if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n) continue;
        // Second, push 1 cells visited for the first time to the queue
        if (ret[new_i][new_j] > ret[i][j] + 1) {
          ret[new_i][new_j] = ret[i][j] + 1;
          q.push({new_i, new_j});
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix, expected;

  matrix = {
    {0,0,0},
    {0,1,0},
    {0,0,0}
  };
  EXPECT_EQ(matrix, sol.updateMatrix(matrix));

  matrix = {
    {0,0,0},
    {0,1,0},
    {1,1,1}
  };
  expected = {
    {0,0,0},
    {0,1,0},
    {1,2,1}
  };
  EXPECT_EQ(expected, sol.updateMatrix(matrix));

  matrix = {
    {1,1,1},
    {1,1,0},
    {1,0,1}
  };
  expected = {
    {3,2,1},
    {2,1,0},
    {1,0,1}
  };
  EXPECT_EQ(expected, sol.updateMatrix(matrix));

  matrix = {
    {1,0,1,1,0,0,1,0,0,1},
    {0,1,1,0,1,0,1,0,1,1},
    {0,0,1,0,1,0,0,1,0,0},
    {1,0,1,0,1,1,1,1,1,1},
    {0,1,0,1,1,0,0,0,0,1},
    {0,0,1,0,1,1,1,0,1,0},
    {0,1,0,1,0,1,0,0,1,1},
    {1,0,0,0,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,0,1,0},
    {1,1,1,1,0,1,0,0,1,1}
  };
  expected = {
    {1,0,1,1,0,0,1,0,0,1},
    {0,1,1,0,1,0,1,0,1,1},
    {0,0,1,0,1,0,0,1,0,0},
    {1,0,1,0,1,1,1,1,1,1},
    {0,1,0,1,1,0,0,0,0,1},
    {0,0,1,0,1,1,1,0,1,0},
    {0,1,0,1,0,1,0,0,1,1},
    {1,0,0,0,1,2,1,1,0,1},
    {2,1,1,1,1,2,1,0,1,0},
    {3,2,2,1,0,1,0,0,1,1}
  };
  EXPECT_EQ(expected, sol.updateMatrix(matrix));

  exit(EXIT_SUCCESS);
}
