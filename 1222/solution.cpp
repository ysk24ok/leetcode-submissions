#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<vector<int>> answer;
    for (auto& queen : queens) {
      int diff_row = queen[0] - king[0];
      int diff_column = queen[1] - king[1];
      int move_row = 0;
      int move_col = 0;
      // same row
      if (diff_row == 0) {
        // queen is right
        if (diff_column > 0) {
          move_col = -1;
        // queen is left
        } else {
          move_col = 1;
        }
      // same column
      } else if (diff_column == 0) {
        // queen is lower
        if (diff_row > 0) {
          move_row = -1;
        // queen is upper
        } else {
          move_row = 1;
        }
      // same diagonal line
      } else if (std::abs(diff_row) == std::abs(diff_column)) {
        // queen is lower right
        if (diff_row > 0 && diff_column > 0) {
          move_row = -1;
          move_col = -1;
        // queen is upper right
        } else if (diff_row > 0 && diff_column < 0) {
          move_row = -1;
          move_col = 1;
        // queen is lower left
        } else if (diff_row < 0 && diff_column > 0) {
          move_row = 1;
          move_col = -1;
        } else if (diff_row < 0 && diff_column < 0) {
          move_row = 1;
          move_col = 1;
        }
      } else {
        continue;
      }
      vector<int> cur_queen = queen;
      cur_queen[0] += move_row;
      cur_queen[1] += move_col;
      while (true) {
        if (cur_queen[0] == king[0] && cur_queen[1] == king[1]) {
          answer.push_back(queen);
          break;
        }
        if (checkQueenExist(queens, cur_queen)) {
          break;
        }
        cur_queen[0] += move_row;
        cur_queen[1] += move_col;
      }
    }
    return answer;
  }

  bool checkQueenExist(vector<vector<int>>& queens, vector<int> cur_queen) {
    for (auto& queen : queens) {
      if (queen[0] == cur_queen[0] && queen[1] == cur_queen[1]) return true;
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> queens;
  vector<int> king;
  vector<vector<int>> got;

  queens = {{0,1},{1,0},{4,0},{0,4},{3,3},{2,4}};
  king = {0, 0};
  got = sol.queensAttacktheKing(queens, king);
  assert(got[0][0] == 0 && got[0][1] == 1);
  assert(got[1][0] == 1 && got[1][1] == 0);
  assert(got[2][0] == 3 && got[2][1] == 3);

  queens = {{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}};
  king = {3,3};
  got = sol.queensAttacktheKing(queens, king);
  assert(got[0][0] == 2 && got[0][1] == 2);
  assert(got[1][0] == 3 && got[1][1] == 4);
  assert(got[2][0] == 4 && got[2][1] == 4);
}
