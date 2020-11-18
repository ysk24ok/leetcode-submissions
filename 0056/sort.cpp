#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    auto comp = [](const vector<int>& left, const vector<int>& right) {
      return left[0] < right[0];
    };
    sort(intervals.begin(), intervals.end(), comp);
    vector<vector<int>> ret;
    vector<int> curr_interval = intervals[0];
    for (size_t i = 1; i < intervals.size(); ++i) {
      const vector<int>& interval = intervals[i];
      // not overlapping
      if (curr_interval[1] < interval[0]) {
        ret.push_back(curr_interval);
        curr_interval = interval;
      // overlapping
      } else {
        curr_interval[1] = max(curr_interval[1], interval[1]);
      }
    }
    ret.push_back(curr_interval);
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> intervals, expected;

  intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  expected = {{1, 6}, {8, 10}, {15, 18}};
  EXPECT_EQ(expected, sol.merge(intervals));

  intervals = {{1, 4}, {4, 5}};
  expected = {{1, 5}};
  EXPECT_EQ(expected, sol.merge(intervals));

  intervals = {{1, 4}, {2, 3}};
  expected = {{1, 4}};
  EXPECT_EQ(expected, sol.merge(intervals));

  exit(EXIT_SUCCESS);
}
