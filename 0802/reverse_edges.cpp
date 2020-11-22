#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<vector<int>> incoming_graph = getReversedGraph(graph);
    queue<int> q;
    vector<int> ret;
    for (int node = 0; node < graph.size(); node++) {
      if (graph[node].size() == 0) {
        q.push(node);
        ret.push_back(node);
      }
    }
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (const int& incoming_node: incoming_graph[node]) {
        RemoveEdge(graph, incoming_node, node);
        // If there is no outgoing edge, this node is terminal
        if (graph[incoming_node].size() == 0) {
          q.push(incoming_node);
          ret.push_back(incoming_node);
        }
      }
    }
    sort(ret.begin(), ret.end());
    return ret;
  }

  vector<vector<int>> getReversedGraph(const vector<vector<int>>& graph) {
    vector<vector<int>> reversed_graph(graph.size(), vector<int>());
    for (int i = 0; i < graph.size(); i++) {
      for (auto& incoming_node : graph[i]) {
        reversed_graph[incoming_node].push_back(i);
      }
    }
    return reversed_graph;
  }

  void RemoveEdge(vector<vector<int>>& graph, int in_node, int out_node) {
    auto it = find(graph[in_node].begin(), graph[in_node].end(), out_node);
    graph[in_node].erase(it);
  }
};

int main() {
  Solution sol;
  vector<vector<int>> graph;
  vector<vector<int>> expected_reversed_graph;
  vector<int> expected;

  graph = {{1,2},{2,3},{5},{0},{5},{},{}};
  expected_reversed_graph = {{3},{0},{0,1},{1},{},{2,4},{}};
  EXPECT_EQ(expected_reversed_graph, sol.getReversedGraph(graph));
  expected = {2,4,5,6};
  EXPECT_EQ(expected, sol.eventualSafeNodes(graph));

  graph = {};
  expected = {};
  EXPECT_EQ(expected, sol.eventualSafeNodes(graph));

  graph = {{0,1,8},{4,5,8},{3,5,6,8},{4,5,6,7,8,9},{5},{},{3,8},{8,9},{9},{8}};
  expected_reversed_graph = {{0},{0},{},{2,6},{1,3},{1,2,3,4},{2,3},{3},{0,1,2,3,6,7,9},{3,7,8}};
  EXPECT_EQ(expected_reversed_graph, sol.getReversedGraph(graph));
  expected = {4,5};
  EXPECT_EQ(expected, sol.eventualSafeNodes(graph));

  exit(EXIT_SUCCESS);
}
