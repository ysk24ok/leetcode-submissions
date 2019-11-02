#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ret;
    vector<size_t> queens;
    recursive(ret, queens, n);
    return ret;
  }

  void recursive(vector<vector<string>>& ret, vector<size_t>& queens, int n) {
    size_t num_queens = queens.size();
    if (num_queens == n) {
      ret.push_back(convertIntoBoard(queens, n));
      return;
    }
    for (int column_id = 0; column_id < n; column_id++) {
      if (!IsValidColumn(column_id, queens, n)) {
        continue;
      }
      vector<size_t> new_queens = queens;
      new_queens.push_back(column_id);
      recursive(ret, new_queens, n);
    }
  }

  bool IsValidColumn(size_t column_id, const vector<size_t>& queens, int n) {
    size_t current_row_id = queens.size();
    if (current_row_id == 0) return true;
    for (int row_id = current_row_id - 1,
             left_column_id = column_id - 1,
             right_column_id = column_id + 1;
         row_id >= 0;
         row_id--, left_column_id--, right_column_id++) {
      if (queens[row_id] == column_id) {
        return false;
      }
      if (left_column_id >= 0 && queens[row_id] == left_column_id) {
        return false;
      }
      if (right_column_id < n && queens[row_id] == right_column_id) {
        return false;
      }
    }
    return true;
  }

  vector<string> convertIntoBoard(const vector<size_t>& queens, int n) {
    vector<string> board;
    for (int row_id = 0; row_id < n; row_id++) {
      size_t column = queens[row_id];
      board.push_back(getRow(column, n));
    }
    return board;
  }

  string getRow(size_t column, int n) {
    string s;
    for (int column_id = 0; column_id < n; column_id++) {
      s += column == column_id ? "Q" : ".";
    }
    return s;
  }
};

void printAnswer(vector<vector<string>>& got) {
  for (size_t i = 0; i < got.size(); i++) {
    for (auto& row : got[i]) {
      cout << row << endl;
    }
    cout << endl;
  }
}

int main() {
  Solution sol;
  vector<vector<string>> got;

  got = sol.solveNQueens(0);
  printAnswer(got);

  got = sol.solveNQueens(1);
  printAnswer(got);

  got = sol.solveNQueens(2);
  printAnswer(got);

  got = sol.solveNQueens(3);
  printAnswer(got);

  got = sol.solveNQueens(4);
  printAnswer(got);

  got = sol.solveNQueens(5);
  printAnswer(got);

  got = sol.solveNQueens(6);
  printAnswer(got);

  got = sol.solveNQueens(10);
  printAnswer(got);
}
