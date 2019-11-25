#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

// XXX: TLE
class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> ret(m, vector<int>(n, numeric_limits<int>::max()));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        init(visited);
        ret[i][j] = min(dfs(matrix, visited, ret, i, j), ret[i][j]);
      }
    }
    return ret;
  }

  void init(vector<vector<bool>>& visited) {
    int m = visited.size(), n = visited[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        visited[i][j] = false;
      }
    }
  }

  int dfs(const vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<int>>& ret, int i, int j) {
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
      return numeric_limits<int>::max();
    }
    if (matrix[i][j] == 0) {
      ret[i][j] = 0;
      return ret[i][j] + 1;
    }
    if (visited[i][j]) {
      return ret[i][j] < numeric_limits<int>::max() ? ret[i][j] + 1 : ret[i][j];
    }
    visited[i][j] = true;
    int d1 = dfs(matrix, visited, ret, i+1, j);
    int d2 = dfs(matrix, visited, ret, i, j+1);
    int d3 = dfs(matrix, visited, ret, i-1, j);
    int d4 = dfs(matrix, visited, ret, i, j-1);
    ret[i][j] = min({d1, d2, d3, d4, ret[i][j]});
    return ret[i][j] < numeric_limits<int>::max() ? ret[i][j] + 1 : ret[i][j];
  }
};

void print_matrix(const vector<vector<int>>& matrix) {
  for (auto& row : matrix) {
    for (auto& e : row) {
      cout << e << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  Solution sol;
  vector<vector<int>> matrix;
  vector<vector<int>> got;
  vector<vector<int>> expected;

  matrix = {
    {0,0,0},
    {0,1,0},
    {0,0,0}
  };
  got = sol.updateMatrix(matrix);
  assert(matrix.size() == got.size());
  print_matrix(got);
  for (int i = 0; i < matrix.size(); i++) {
    assert(matrix[i] == got[i]);
  }

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
  got = sol.updateMatrix(matrix);
  assert(matrix.size() == got.size());
  print_matrix(got);
  for (int i = 0; i < got.size(); i++) {
    assert(got[i] == expected[i]);
  }

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
  got = sol.updateMatrix(matrix);
  assert(matrix.size() == got.size());
  print_matrix(got);
  for (int i = 0; i < got.size(); i++) {
    assert(got[i] == expected[i]);
  }

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
  got = sol.updateMatrix(matrix);
  assert(matrix.size() == got.size());
  print_matrix(got);
  for (int i = 0; i < got.size(); i++) {
    assert(got[i] == expected[i]);
  }
}
