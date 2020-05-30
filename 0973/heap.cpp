#include <cstdlib>
#include <queue>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

// descending order
auto compare = [](const pair<size_t, long>& left, const pair<size_t, long>& right) {
  return left.second > right.second;
};

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<size_t, long>, vector<pair<size_t, long>>, decltype(compare)> pq(compare);
    for (size_t i = 0, m = points.size(); i < m; ++i) {
      const auto& point = points[i];
      long dist = point[0] * point[0] + point[1] * point[1];
      pq.push({i, dist});
    }
    vector<vector<int>> ret(K);
    for (int i = 0; i < K; ++i) {
      ret[i] = points[pq.top().first];
      pq.pop();
    }
    return ret;
  }
};

void check(const vector<vector<int>>& expected, const vector<vector<int>>& got) {
  ASSERT_EQ(expected.size(), got.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(expected[i][0], got[i][0]);
    EXPECT_EQ(expected[i][1], got[i][1]);
  }
}

int main() {
  Solution sol;
  vector<vector<int>> points, got, expected;
  int K;

  // sqrt(10), sqrt(8)
  points = {{1,3},{-2,2}};
  K = 1;
  expected = {{-2,2}};
  got = sol.kClosest(points, K);
  check(expected, got);

  // sqrt(18), sqrt(26), sqrt(20)
  points = {{3,3},{5,-1},{-2,4}};
  K = 2;
  expected = {{3,3},{-2,4}};
  got = sol.kClosest(points, K);
  check(expected, got);

  exit(EXIT_SUCCESS);
}
