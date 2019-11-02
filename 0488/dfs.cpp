#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>

using namespace std;

class Solution {
 public:
  int findMinStep(string board, string hand) {
    cout << endl;
    std::sort(hand.begin(), hand.end());
    int min_ball = numeric_limits<int>::max();
    do {
      min_ball = min(dfs(board, hand, 0), min_ball);
    } while(std::next_permutation(hand.begin(), hand.end()));
    if (min_ball == numeric_limits<int>::max()) return -1;
    return min_ball;
  }

  int dfs(string board, const string& hand, int hand_index) {
    if (hand_index == hand.size()) {
      return numeric_limits<int>::max();
    }
    char hand_char = hand[hand_index];
    int min_ball = numeric_limits<int>::max();
    for (int board_index = 0; board_index < board.size(); board_index++) {
      char current_char_in_board = board[board_index];
      if (hand_char != current_char_in_board) continue;
      if (board_index + 1 == board.size()) continue;
      if (hand_char == current_char_in_board) {
        string new_board = removeConsecutiveBalls(board, current_char_in_board, board_index);
        if (new_board.size() == 0) return 1;
        min_ball = min(dfs(new_board, hand, hand_index+1), min_ball);
      }
    }
    cout << board << ", " << hand.substr(hand_index) << ", " << min_ball << endl;
    if (min_ball == numeric_limits<int>::max()) return min_ball;
    return min_ball + 1;
  }

  string removeConsecutiveBalls(string board, char c, int index) {
    cout << "board: " << board << ", c: " << c << ", index: " << index << endl;
    assert(board[index] == c);
    // add the ball to the board
    //  "WWGGY", "Y" -> "WWGGYY"
    //  "WWYR", "Y" -> "WWYYR"
    string new_board;
    if (index + 1 == board.size() || board[index+1] != c) {
      for (int i = 0; i < board.size(); i++) {
        if (i == index) {
          new_board += c;
        }
        new_board += board[i];
      }
      cout << "hoge: " << new_board << endl;
      return new_board;
    }
    // otherwise, remove contiguous balls
    //  "YYWW", "W" -> "YY"
    //  "WWYY", "W" -> "YY"
    //  "YWWY", "W" -> "YY"
    //  "YWWYYG", "W" -> "G"
    //  "GGRYYWWYRRGG", "W" -> ""
    assert(board[index+1] == c);
    int start_idx = index;
    int end_idx = index + 1;
    int interval = 2;
    while (true) {
      start_idx -= 1;
      end_idx += 1;
      if (start_idx < 0 || end_idx > board.size() - 1) break;
      if (board[start_idx] != board[end_idx]) break;
      while (start_idx >= 1 && board[start_idx-1] == board[start_idx]) start_idx--;
      while (end_idx <= board.size()-2 && board[end_idx+1] == board[end_idx]) end_idx++;
      if (end_idx - start_idx + 1 - interval < 3) break;
    }
    for (int i = 0; i < board.size(); i++) {
      if (i <= start_idx || i >= end_idx) {
        new_board += board[i];
      }
    }
    cout << start_idx << ", " << end_idx << ", " << new_board << endl;
    return new_board;
  }
};

int main() {
  Solution sol;

  assert(sol.findMinStep("WWRRBBWW", "WRBRW") == 2);
  assert(sol.removeConsecutiveBalls("WWRRW", 'R', 2) == "");
  assert(sol.removeConsecutiveBalls("YYWW", 'W', 2) == "YY");
  assert(sol.removeConsecutiveBalls("WWYY", 'W', 0) == "YY");
  assert(sol.removeConsecutiveBalls("YWWY", 'W', 1) == "YY");
  assert(sol.removeConsecutiveBalls("YWWYYG", 'W', 1) == "G");
  assert(sol.removeConsecutiveBalls("GGRYYWWYRRGG", 'W', 5) == "");

  assert(sol.findMinStep("WWRRW", "R") == 1);
  assert(sol.findMinStep("WRRBBW", "RB") == -1);
  assert(sol.findMinStep("WWRRBBWW", "WRBRW") == 2);
  assert(sol.findMinStep("G", "GGGGG") == 2);
  assert(sol.findMinStep("RBYYBBRRB", "YRBGB") == 3);
}
