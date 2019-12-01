#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> is_safe(graph.size(), -1);
    vector<int> ret;
    for (int node = 0; node < graph.size(); node++) {
      if (dfs(graph, node, is_safe)) {
        ret.push_back(node);
      }
    }
    return ret;
  }

  bool dfs(const vector<vector<int>>& graph, int node, vector<int>& is_safe) {
    if (is_safe[node] != -1) return is_safe[node] == 1;
    is_safe[node] = 0;
    for (auto& outgoing_node : graph[node]) {
      if (!dfs(graph, outgoing_node, is_safe)) {
        return false;
      }
    }
    is_safe[node] = 1;
    return true;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> graph;
  vector<vector<int>> expected_reversed_graph;
  vector<int> got;
  vector<int> expected;

  graph = {{1,2},{2,3},{5},{0},{5},{},{}};
  expected = {2,4,5,6};
  got = sol.eventualSafeNodes(graph);
  assert(got == expected);

  graph = {};
  got = sol.eventualSafeNodes(graph);
  assert(got.size() == 0);

  graph = {{0,1,8},{4,5,8},{3,5,6,8},{4,5,6,7,8,9},{5},{},{3,8},{8,9},{9},{8}};
  expected = {4,5};
  got = sol.eventualSafeNodes(graph);
  assert(got == expected);
}
