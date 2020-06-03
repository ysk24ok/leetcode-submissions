#include <cstdlib>
#include <queue>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int ret = 0;
    int count = 0;
    const size_t m = costs.size(), N = m / 2;
    auto greater = [](const pair<size_t, int>& left, const pair<size_t, int>& right) {
      return left.second > right.second;
    };
    priority_queue<pair<size_t, int>, vector<pair<size_t, int>>, decltype(greater)> pq(greater);
    for (size_t i = 0; i < m; ++i) {
      pq.push({i, costs[i][0] - costs[i][1]});
    }
    while (!pq.empty()) {
      pair<size_t, int> p = pq.top();
      pq.pop();
      if (count >= N) {
        ret += costs[p.first][1];
      } else {
        ret += costs[p.first][0];
      }
      count++;
    }
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
