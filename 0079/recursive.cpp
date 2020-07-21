#include <cassert>
#include <cstdlib>
#include <string>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    for (int row_idx = 0; row_idx < board.size(); row_idx++) {
      for (int col_idx = 0; col_idx < board[row_idx].size(); col_idx++) {
        if (board[row_idx][col_idx] != word[0]) {
          continue;
        }
        if (recursive(board, row_idx, col_idx, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  bool recursive(vector<vector<char>>& board, int row_idx, int col_idx, const string& word, size_t word_idx) {
    if (row_idx < 0 || row_idx >= board.size() || col_idx < 0 || col_idx >= board[row_idx].size()) {
      return false;
    }
    if (board[row_idx][col_idx] != word[word_idx]) {
      return false;
    }
    if (word_idx == word.size() - 1) {
      return true;
    }
    const char temp = board[row_idx][col_idx];
    board[row_idx][col_idx] = '#';
    bool found = recursive(board, row_idx+1, col_idx, word, word_idx+1) ||
                 recursive(board, row_idx-1, col_idx, word, word_idx+1) ||
                 recursive(board, row_idx, col_idx+1, word, word_idx+1) ||
                 recursive(board, row_idx, col_idx-1, word, word_idx+1);
    board[row_idx][col_idx] = temp;
    return found;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> board;
  string word;

  board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };
  word = "ABCCED";
  EXPECT_TRUE(sol.exist(board, word));
  word = "SEE";
  EXPECT_TRUE(sol.exist(board, word));
  word = "ABCB";
  EXPECT_FALSE(sol.exist(board, word));

  exit(EXIT_SUCCESS);
}
