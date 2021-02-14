#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> groups(graph.size(), -1);
    for (int node = 0; node < graph.size(); ++node) {
      if (groups[node] == -1 && !dfs(graph, groups, node, 0)) {
        return false;
      }
    }
    return true;
  }

  bool dfs(const vector<vector<int>>& graph, vector<int>& groups, int node, int group) {
    if (groups[node] != -1) {
      return groups[node] == group;
    }
    groups[node] = group;
    int neighbor_group = group == 0 ? 1 : 0;
    for (const int& neighbor_node : graph[node]) {
      if (!dfs(graph, groups, neighbor_node, neighbor_group)) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> graph;
  bool expected;

  graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}}, expected = true;
  EXPECT_EQ(expected, sol.isBipartite(graph));

  graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}, expected = false;
  EXPECT_EQ(expected, sol.isBipartite(graph));

  graph = {{}, {2, 4, 6}, {1, 4, 8, 9}, {7, 8}, {1, 2, 8, 9}, {6, 9}, {1, 5, 7, 8, 9}, {3, 6, 9}, {2, 3, 4, 6, 9}, {2, 4, 5, 6, 7, 8}}, expected = false;

  exit(EXIT_SUCCESS);
}
