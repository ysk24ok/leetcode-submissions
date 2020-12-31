#include <gtest/gtest.h>

#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

vector<pair<int, int>> moves = {
  {0, 1},
  {1, 1},
  {1, 0},
  {1,-1},
  {0, -1},
  {-1, -1},
  {-1, 0},
  {-1, 1}
};

// 2: live now, dead originally
// 1: live
// 0: dead
// -1: dead now, live originally
class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    const size_t m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int num_live_neighbors = 0;
        for (const auto& move : moves) {
          int neighbor_i = i + move.first;
          int neighbor_j = j + move.second;
          if (neighbor_i >= 0 && neighbor_i < m && neighbor_j >= 0 && neighbor_j < n && abs(board[neighbor_i][neighbor_j]) == 1) {
            num_live_neighbors++;
          }
        }
        if (board[i][j] == 1 && (num_live_neighbors < 2 || num_live_neighbors > 3)) {
          board[i][j] = -1;
        } else if (board[i][j] == 0 && num_live_neighbors == 3) {
          board[i][j] = 2;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 2) { board[i][j] = 1; }
        else if (board[i][j] == -1) { board[i][j] = 0; }
      }
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> board, expected;

  board = {
    {0, 1, 0},
    {0, 0, 1},
    {1, 1, 1},
    {0, 0, 0},
  };
  expected = {
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 1},
    {0, 1, 0},
  };
  sol.gameOfLife(board);
  EXPECT_EQ(expected, board);

  board = {
    {1, 1},
    {1, 0},
  };
  expected = {
    {1, 1},
    {1, 1},
  };
  sol.gameOfLife(board);
  EXPECT_EQ(expected, board);

  exit(EXIT_SUCCESS);
}
