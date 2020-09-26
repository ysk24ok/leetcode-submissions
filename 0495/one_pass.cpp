#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    const size_t n = timeSeries.size();
    int ret = 0;
    if (n == 0) { return ret; }
    int prev_ts = timeSeries[0];
    for (size_t i = 1; i < n; ++i) {
      if (prev_ts + duration <= timeSeries[i]) {
        ret += duration;
      } else {
        ret += (timeSeries[i] - prev_ts);
      }
      prev_ts = timeSeries[i];
    }
    ret += duration;
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> timeSeries;
  int duration;
  int expected;

  timeSeries = {1, 4}, duration = 2;
  expected = 4;
  EXPECT_EQ(expected, sol.findPoisonedDuration(timeSeries, duration));

  timeSeries = {1, 2}, duration = 2;
  expected = 3;
  EXPECT_EQ(expected, sol.findPoisonedDuration(timeSeries, duration));

  timeSeries = {1}, duration = 2;
  expected = 2;
  EXPECT_EQ(expected, sol.findPoisonedDuration(timeSeries, duration));

  timeSeries = {}, duration = 2;
  expected = 0;
  EXPECT_EQ(expected, sol.findPoisonedDuration(timeSeries, duration));

  exit(EXIT_SUCCESS);
}
