#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isRobotBounded(string instructions) {
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int idx = 0;
    pair<int, int> position = {0, 0};
    for (const char& c : instructions) {
      if (c == 'L') {
        idx += 3;
        idx %= 4;
      } else if (c == 'R') {
        idx += 1;
        idx %= 4;
      } else {
        position.first += moves[idx].first;
        position.second += moves[idx].second;
      }
    }
    if (position.first == 0 and position.second == 0) { return true; }
    else if (idx == 1 or idx == 2 or idx == 3) { return true; }
    else { return false; }
  }
};

int main() {
  Solution sol;
  string instructions;

  instructions = "GGLLGG";
  EXPECT_TRUE(sol.isRobotBounded(instructions));

  instructions = "GG";
  EXPECT_FALSE(sol.isRobotBounded(instructions));

  instructions = "GL";
  EXPECT_TRUE(sol.isRobotBounded(instructions));

  exit(EXIT_SUCCESS);
}
