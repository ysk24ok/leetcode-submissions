#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    const size_t m = board.size();
    if (m == 0) { return; }
    const size_t n = board[0].size();
    // check boundary
    for (size_t i = 0; i < m; ++i) {
      if (board[i][0] == 'O') { setBoundary(board, i, 0); }
      if (board[i][n-1] == 'O') { setBoundary(board, i, n-1); }
    }
    for (size_t j = 0; j < n; ++j) {
      if (board[0][j] == 'O') { setBoundary(board, 0, j); }
      if (board[m-1][j] == 'O') { setBoundary(board, m-1, j); }
    }
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        if (board[i][j] == 'O') { dfs(board, i, j); }
        else if (board[i][j] == '-') { board[i][j] = 'O'; }
      }
    }
  }

  void setBoundary(vector<vector<char>>& board, size_t i, size_t j) {
    if (i >= board.size() || j >= board[i].size()) { return; }
    if (board[i][j] != 'O') { return; }
    board[i][j] = '-';
    if (i > 0) { setBoundary(board, i - 1, j); }
    if (j > 0) { setBoundary(board, i, j - 1); }
    setBoundary(board, i + 1, j);
    setBoundary(board, i, j + 1);
  }

  void dfs(vector<vector<char>>& board, size_t i, size_t j) {
    if (i >= board.size() || j >= board[i].size()) { return; }
    if (board[i][j] == 'X') { return; }
    board[i][j] = 'X';
    if (i > 0) { dfs(board, i - 1, j); }
    if (j > 0) { dfs(board, i, j - 1); }
    dfs(board, i + 1, j);
    dfs(board, i, j + 1);
  }
};

int main() {
  Solution sol;
  vector<vector<char>> board, expected;

  board = {
    {'X','X','X','X'},
    {'X','O','O','X'},
    {'X','X','O','X'},
    {'X','O','X','X'},
  };
  expected = {
    {'X','X','X','X'},
    {'X','X','X','X'},
    {'X','X','X','X'},
    {'X','O','X','X'},
  };
  sol.solve(board);
  EXPECT_EQ(expected, board);

  board = {
    {'X','X','X','X'},
    {'X','O','O','X'},
    {'X','X','O','O'},
    {'X','X','X','X'},
  };
  expected = {
    {'X','X','X','X'},
    {'X','O','O','X'},
    {'X','X','O','O'},
    {'X','X','X','X'},
  };
  sol.solve(board);
  EXPECT_EQ(expected, board);

  exit(EXIT_SUCCESS);
}
