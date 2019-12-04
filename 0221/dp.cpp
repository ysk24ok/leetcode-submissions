#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// time complexity: O(MN)
// time complexity: O(MN)
// I have used DFS to calculate left-upper corner of the matrix,
// but realized calculating right-lower corner make DFS unnecessary.
// Just a simple DP problem.
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ret = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '0') continue;
        if (dp[i][j] == -1) {
          ret = max(dfs(i, j, matrix, dp), ret);
        } else {
          ret = max(dp[i][j], ret);
        }
      }
    }
    return ret * ret;
  }

  int dfs(int i, int j, const vector<vector<char>>& matrix, vector<vector<int>>& dp) {
    if (i >= matrix.size() || j >= matrix[0].size()) return 0;
    if (matrix[i][j] == '0') return 0;
    if (dp[i][j] >= 0) return dp[i][j];
    int ret1 = dfs(i+1, j, matrix, dp);
    int ret2 = dfs(i, j+1, matrix, dp);
    int ret3 = dfs(i+1, j+1, matrix, dp);
    int ret = min({ret1, ret2, ret3}) + 1;
    dp[i][j] = ret;
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> matrix;

  matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'},
  };
  assert(sol.maximalSquare(matrix) == 4);

  matrix = {
    {'0','1','1','1','0'},
    {'1','1','1','0','0'},
    {'1','1','1','1','0'},
    {'1','1','1','1','0'},
  };
  assert(sol.maximalSquare(matrix) == 9);

  matrix = {
    {'0','1','1','1','0'},
    {'1','1','0','0','0'},
    {'0','1','1','0','0'},
    {'1','0','1','1','0'},
  };
  assert(sol.maximalSquare(matrix) == 1);

  matrix = {};
  assert(sol.maximalSquare(matrix) == 0);
}
