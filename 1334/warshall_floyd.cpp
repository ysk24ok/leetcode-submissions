#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    static int maximum = 10e7;
    vector<vector<int>> dp(n, vector<int>(n, maximum));
    for (const auto& edge : edges) {
      dp[edge[0]][edge[1]] = edge[2];
      dp[edge[1]][edge[0]] = edge[2];
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    int ret = 0;
    int ret_count = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
      int count = 0;
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (dp[i][j] <= distanceThreshold) count++;
      }
      if (count <= ret_count) {
        ret_count = count;
        ret = i;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int n, distanceThreshold;
  vector<vector<int>> edges;

  n = 4, distanceThreshold = 4;
  edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
  assert(sol.findTheCity(n, edges, distanceThreshold) == 3);

  n = 5, distanceThreshold = 2;
  edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
  assert(sol.findTheCity(n, edges, distanceThreshold) == 0);
}
