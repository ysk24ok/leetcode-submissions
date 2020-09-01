#include <gtest/gtest.h>

#include <vector>

using namespace std;

class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int x_diff_base = coordinates[1][0] - coordinates[0][0];
    int y_diff_base = coordinates[1][1] - coordinates[0][1];
    for (size_t i = 2, m = coordinates.size(); i < m; ++i) {
      int x_diff = coordinates[i][0] - coordinates[0][0];
      int y_diff = coordinates[i][1] - coordinates[0][1];
      float x_rate;
      float y_rate;
      if (x_diff_base != 0 && y_diff_base != 0) {
        x_rate = x_diff / x_diff_base;
        y_rate = y_diff / y_diff_base;
        if (x_rate != y_rate) { return false; }
      } else if (x_diff_base != 0 && y_diff_base == 0) {
        if (y_diff != 0) { return false; }
      } else if (x_diff_base == 0 && y_diff_base != 0) {
        if (x_diff != 0) { return false; }
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> coordinates;

  coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
  EXPECT_TRUE(sol.checkStraightLine(coordinates));

  coordinates = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
  EXPECT_FALSE(sol.checkStraightLine(coordinates));

  coordinates = {{-3,-2},{-1,-2},{2,-2},{-2,-2},{0,-2}};
  EXPECT_TRUE(sol.checkStraightLine(coordinates));
}
