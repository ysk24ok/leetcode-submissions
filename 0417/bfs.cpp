#include <gtest/gtest.h>

#include <array>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

const array<pair<int, int>, 4> directions = {make_pair(0, 1), {0, -1}, {1, 0}, {-1, 0}};

class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) { return {}; }
    const size_t m = matrix.size(), n = matrix[0].size();
    vector<vector<bool>> visited_pacific(m, vector<bool>(n));
    queue<pair<int, int>> queue_pacific;
    for (size_t i = 0; i < m; ++i) { queue_pacific.push({i, 0}); }
    for (size_t j = 1; j < n; ++j) { queue_pacific.push({0, j}); }
    bfs(matrix, queue_pacific, visited_pacific);

    vector<vector<bool>> visited_atlantic(m, vector<bool>(n));
    queue<pair<int, int>> queue_atlantic;
    for (size_t i = 0; i < m; ++i) { queue_atlantic.push({i, n - 1}); }
    for (size_t j = 0; j < n - 1; ++j) { queue_atlantic.push({m - 1, j}); }
    bfs(matrix, queue_atlantic, visited_atlantic);

    vector<vector<int>> ret;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (visited_pacific[i][j] && visited_atlantic[i][j]) {
          ret.push_back({i, j});
        }
      }
    }
    return ret;
  }

  void bfs(const vector<vector<int>>& matrix, queue<pair<int, int>>& q,
           vector<vector<bool>>& visited) {
    const size_t m = matrix.size(), n = matrix[0].size();
    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      visited[i][j] = true;
      for (const auto& direction : directions) {
        int new_i = i + direction.first;
        int new_j = j + direction.second;
        if (new_i < 0 || new_j < 0 || new_i >= m || new_j >= n || visited[new_i][new_j]) {
          continue;
        }
        if (matrix[new_i][new_j] >= matrix[i][j]) {
          q.push({new_i, new_j});
        }
      }
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> matrix, expected;

  matrix = {
    {1, 2, 2, 3, 5},
    {3, 2, 3, 4, 4},
    {2, 4, 5, 3, 1},
    {6, 7, 1, 4, 5},
    {5, 1, 1, 2, 4}
  };
  expected = {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}};
  EXPECT_EQ(expected, sol.pacificAtlantic(matrix));

  matrix = {}, expected = {};
  EXPECT_EQ(expected, sol.pacificAtlantic(matrix));

  exit(EXIT_SUCCESS);
}
