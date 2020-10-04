#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    // move a long interval to left
    auto compare = [](const vector<int>& left, const vector<int>& right) {
      if (left[0] != right[0]) { return left[0] < right[0]; }
      else { return left[1] > right[1]; }
    };
    sort(intervals.begin(), intervals.end(), compare);
    int ret = 1;
    vector<int>& curr_interval = intervals[0];
    for (size_t i = 1; i < intervals.size(); ++i) {
      // when intervals[i] is covered by curr_interval
      if (curr_interval[0] <= intervals[i][0] && intervals[i][1] <= curr_interval[1]) {
        continue;
      } else {
        ret++;
        curr_interval = intervals[i];
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> intervals;
  int expected;

  intervals = {{1, 4}, {3, 6}, {2, 8}};
  expected = 2;
  EXPECT_EQ(expected, sol.removeCoveredIntervals(intervals));

  intervals = {{1, 4}, {2, 3}};
  expected = 1;
  EXPECT_EQ(expected, sol.removeCoveredIntervals(intervals));

  intervals = {{0, 10}, {5, 12}};
  expected = 2;
  EXPECT_EQ(expected, sol.removeCoveredIntervals(intervals));

  intervals = {{3, 10}, {4, 10}, {5, 11}};
  expected = 2;
  EXPECT_EQ(expected, sol.removeCoveredIntervals(intervals));

  intervals = {{1, 2}, {1, 4}, {3, 4}};
  expected = 1;
  EXPECT_EQ(expected, sol.removeCoveredIntervals(intervals));

  intervals = {{1, 10}, {2, 8}, {3, 9}};
  expected = 1;
  EXPECT_EQ(expected, sol.removeCoveredIntervals(intervals));

  exit(EXIT_SUCCESS);
}
