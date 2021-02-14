#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    // 0 means not visited yet.
    vector<int> labels(graph.size());
    queue<int> q;
    for (int node_idx = 0; node_idx < graph.size(); ++node_idx) {
      if (labels[node_idx] != 0) continue;
      labels[node_idx] = 1;
      q.push(node_idx);
      while (!q.empty()) {
        int node_idx = q.front();
        q.pop();
        assert(labels[node_idx] != 0);
        int label = labels[node_idx] == 1 ? 2 : 1;
        for (auto& neighbor_node_idx : graph[node_idx]) {
          if (labels[neighbor_node_idx] != 0) {
            if (labels[neighbor_node_idx] != label) return false;
          } else {
            labels[neighbor_node_idx] = label;
            q.push(neighbor_node_idx);
          }
        }
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

  graph = {{1,2},{0,2},{0,1}},expected = false;
  EXPECT_EQ(expected, sol.isBipartite(graph));

  graph = {{1}, {0}}, expected = true;
  EXPECT_EQ(expected, sol.isBipartite(graph));

  graph = {{}, {2, 3}, {1, 3}, {1, 2}}, expected = false;
  EXPECT_EQ(expected, sol.isBipartite(graph));

  exit(EXIT_SUCCESS);
}
