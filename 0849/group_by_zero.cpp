#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int ret = 0;
    int distance = 0, idx = 0;
    while (seats[idx] == 0) {
      idx++;
      distance++;
    }
    ret = max(ret, distance);
    int start = idx;
    distance = 0, idx = seats.size() - 1;
    while (seats[idx] == 0) {
      idx--;
      distance++;
    }
    ret = max(ret, distance);
    int last = idx;
    int longest = 0;
    for (int i = start; i <= last; ++i) {
      if (seats[i] == 0) {
        longest++;
      } else {
        ret = max(ret, (longest+1)/2);
        longest = 0;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> seats;
  int expected;

  seats = {1, 0, 0, 0, 1, 0, 1};
  expected = 2;
  EXPECT_EQ(expected, sol.maxDistToClosest(seats));

  seats = {1, 0, 0, 0};
  expected = 3;
  EXPECT_EQ(expected, sol.maxDistToClosest(seats));

  seats = {0, 0, 0, 1};
  expected = 3;
  EXPECT_EQ(expected, sol.maxDistToClosest(seats));

  seats = {1, 0, 1};
  expected = 1;
  EXPECT_EQ(expected, sol.maxDistToClosest(seats));

  seats = {1, 0, 0, 1};
  expected = 1;
  EXPECT_EQ(expected, sol.maxDistToClosest(seats));

  seats = {1, 0, 0, 0, 1};
  expected = 2;
  EXPECT_EQ(expected, sol.maxDistToClosest(seats));

  exit(EXIT_SUCCESS);
}
