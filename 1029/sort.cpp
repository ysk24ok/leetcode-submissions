#include <algorithm>
#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    auto less = [](const vector<int>& left, const vector<int>& right) {
      return (left[0] - left[1]) < (right[0] - right[1]);
    };
    sort(costs.begin(), costs.end(), less);
    const size_t m = costs.size(), N = m / 2;
    int ret = 0;
    for (size_t i = 0; i < N; ++i) { ret += costs[i][0]; }
    for (size_t i = N; i < m; ++i) { ret += costs[i][1]; }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> costs;

  //        -10      -170     350      10
  costs = {{10,20},{30,200},{400,50},{30,20}};
  EXPECT_EQ(110, sol.twoCitySchedCost(costs));

  exit(EXIT_SUCCESS);
}
