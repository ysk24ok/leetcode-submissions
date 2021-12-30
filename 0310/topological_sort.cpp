#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> neighbors(n);
    for (const vector<int>& edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
    vector<int> leaves;
    for (int i = 0; i < n; ++i) {
      // includes isolated nodes
      if (neighbors[i].size() == 1 || neighbors[i].size() == 0) {
        leaves.push_back(i);
      }
    }
    int remaining = n;
    while (remaining > 2) {
      vector<int> new_leaves;
      for (const int& leaf : leaves) {
        // isolated node
        if (neighbors[leaf].size() == 0) { continue; }
        int neighbor = neighbors[leaf][0];
        neighbors[leaf] = {};
        for (auto it = neighbors[neighbor].begin(); it != neighbors[neighbor].end();) {
          if (*it == leaf) {
            it = neighbors[neighbor].erase(it);
          } else {
            ++it;
          }
        }
        if (neighbors[neighbor].size() == 1) {
          new_leaves.push_back(neighbor);
        }
        remaining--;
      }
      leaves.swap(new_leaves);
    }
    return leaves;
  }
};

int main() {
  Solution sol;
  int n;
  vector<vector<int>> edges;
  vector<int> expected;

  n = 4, edges = {{1, 0}, {1, 2}, {1, 3}}, expected = {1};
  EXPECT_EQ(sol.findMinHeightTrees(n, edges), expected);

  n = 6, edges = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}}, expected = {3, 4};
  EXPECT_EQ(sol.findMinHeightTrees(n, edges), expected);

  exit(EXIT_SUCCESS);
}
