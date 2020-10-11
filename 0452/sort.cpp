#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) { return 0; }
    auto compare = [](const vector<int>& left, const vector<int>& right) {
      if (left[0] != right[0]) { return left[0] < right[0]; }
      else { return left[1] < right[1]; }
    };
    sort(points.begin(), points.end(), compare);
    int ret = 1;
    int duplicated_end = points[0][1];
    for (size_t i = 1; i < points.size(); ++i) {
      if (duplicated_end < points[i][0]) {
        ret += 1;
        duplicated_end = points[i][1];
      } else {
        duplicated_end = min(duplicated_end, points[i][1]);
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> points;
  int expected;

  points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  expected = 2;
  EXPECT_EQ(expected, sol.findMinArrowShots(points));

  points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  expected = 4;
  EXPECT_EQ(expected, sol.findMinArrowShots(points));

  points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  expected = 2;
  EXPECT_EQ(expected, sol.findMinArrowShots(points));

  points = {{1, 2}};
  expected = 1;
  EXPECT_EQ(expected, sol.findMinArrowShots(points));

  points = {{2, 3}, {2, 3}};
  expected = 1;
  EXPECT_EQ(expected, sol.findMinArrowShots(points));

  points = {{3, 9}, {7, 12}, {3, 8}, {6, 8}, {9, 10}, {2, 9}, {0, 9}, {3, 9}, {0, 6}, {2, 8}};
  expected = 2;
  EXPECT_EQ(expected, sol.findMinArrowShots(points));

  points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
  expected = 2;
  EXPECT_EQ(expected, sol.findMinArrowShots(points));

  exit(EXIT_SUCCESS);
}
