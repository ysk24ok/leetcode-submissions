#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cstdlib>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

array<pair<int, int>, 4> directions = {make_pair(0, 1), {0, -1}, {-1, 0}, {1, 0}};

class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    const int m = heights.size(), n = heights[0].size();
    auto greater = [](const tuple<int, int, int>& left, const tuple<int, int, int>& right) {
      return get<2>(left) > get<2>(right);
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(greater)> pq(greater);
    vector<vector<int>> dist(m, vector<int>(n, numeric_limits<int>::max()));
    pq.push({0, 0, 0});
    while (!pq.empty()) {
      const tuple<int, int, int>& element = pq.top();
      int r = get<0>(element), c = get<1>(element), d = get<2>(element);
      pq.pop();
      if (r == m - 1 && c == n - 1) {
        return d;
      }
      for (const auto& direction : directions) {
        int new_r = r + direction.first, new_c = c + direction.second;
        if (new_r < 0 || new_r >= m || new_c < 0 || new_c >= n) {
          continue;
        }
        int new_d = max(d, abs(heights[new_r][new_c] - heights[r][c]));
        if (new_d < dist[new_r][new_c]) {
          dist[new_r][new_c] = new_d;
          pq.push({new_r, new_c, new_d});
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> heights;
  int expected;

  heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}}, expected = 2;
  EXPECT_EQ(expected, sol.minimumEffortPath(heights));

  heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}}, expected = 1;
  EXPECT_EQ(expected, sol.minimumEffortPath(heights));

  heights = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}}, expected = 0;
  EXPECT_EQ(expected, sol.minimumEffortPath(heights));

  exit(EXIT_SUCCESS);
}
