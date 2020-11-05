#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCostToMoveChips(vector<int>& position) {
    int num_odd = 0;
    int num_even = 0;
    for (const int& pos : position) {
      if (pos % 2 == 0) {
        num_even++;
      } else {
        num_odd++;
      }
    }
    return num_odd < num_even ? num_odd : num_even;
  }
};

int main() {
  Solution sol;
  vector<int> position;
  int expected;

  position = {1, 2, 3};
  expected = 1;
  EXPECT_EQ(expected, sol.minCostToMoveChips(position));

  position = {2, 2, 2, 3, 3};
  expected = 2;
  EXPECT_EQ(expected, sol.minCostToMoveChips(position));

  position = {1, 1000000000};
  expected = 1;
  EXPECT_EQ(expected, sol.minCostToMoveChips(position));

  exit(EXIT_SUCCESS);
}
