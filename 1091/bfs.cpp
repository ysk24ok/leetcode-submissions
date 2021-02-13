#include <gtest/gtest.h>

#include <array>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

array<pair<int, int>, 8> directions = {
  make_pair(1, 1), {1, 0}, {1, -1}, {0, -1},
  {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}
};

class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    const size_t m = grid.size();
    queue<tuple<size_t, size_t, int>> q;
    if (grid[0][0] == 0) {
      q.push(make_tuple(0, 0, 1));
      grid[0][0] = 1;
    }
    while (!q.empty()) {
      size_t i = get<0>(q.front());
      size_t j = get<1>(q.front());
      int length = get<2>(q.front());
      q.pop();
      if (i == m - 1 && j == m - 1) {
        return length;
      }
      for (const auto& direction : directions) {
        size_t new_i = i + direction.first;
        size_t new_j = j + direction.second;
        if (new_i >= m || new_j >= m) {
          continue;
        }
        if (grid[new_i][new_j] == 0) {
          q.push({new_i, new_j, length + 1});
          grid[new_i][new_j] = 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> grid;
  int expected;

  grid = {
    {0,1},
    {1,0}
  };
  expected = 2;
  EXPECT_EQ(expected, sol.shortestPathBinaryMatrix(grid));

  grid = {
    {0,0,0},
    {1,1,0},
    {1,1,0}
  };
  expected = 4;
  EXPECT_EQ(expected, sol.shortestPathBinaryMatrix(grid));

  grid = {
    {0,1,1,0,0,1},
    {1,0,1,0,1,0},
    {1,0,1,0,1,0},
    {1,0,0,0,1,0},
    {1,1,0,1,1,0},
    {1,1,1,0,0,0},
  };
  expected = 8;
  EXPECT_EQ(expected, sol.shortestPathBinaryMatrix(grid));

  grid = {
    {1,0,0},
    {1,1,0},
    {1,1,0}
  };
  expected = -1;
  EXPECT_EQ(expected, sol.shortestPathBinaryMatrix(grid));

  grid = {
    {0,0},
    {0,1}
  };
  expected = -1;
  EXPECT_EQ(expected, sol.shortestPathBinaryMatrix(grid));
}
