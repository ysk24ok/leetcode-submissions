#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> graph;
    for (size_t i = 0; i < values.size(); ++i) {
      const string& src = equations[i][0];
      const string& dest = equations[i][1];
      graph[src][dest] = values[i];
      graph[dest][src] = 1.0 / values[i];
    }
    vector<double> ret(queries.size());
    for (size_t i = 0; i < queries.size(); ++i) {
      ret[i] = findPath(graph, queries[i]);
    }
    return ret;
  }

 private:
  double findPath(const unordered_map<string, unordered_map<string, double>>& graph,
                  const vector<string>& query) {
    unordered_set<string> visited;
    queue<pair<string, double>> q;
    q.push({query[0], 1.0});
    while (!q.empty()) {
      string src_node = q.front().first;
      double val = q.front().second;
      q.pop();
      visited.insert(src_node);
      if (graph.find(src_node) == graph.end()) {
        return -1.0;
      }
      if (src_node == query[1]) {
        return val;
      }
      for (const auto& next_node : graph.at(src_node)) {
        if (visited.find(next_node.first) == visited.end()) {
          q.push({next_node.first, val * next_node.second});
        }
      }
    }
    return -1.0;
  }
};

int main() {
  Solution sol;
  vector<vector<string>> equations;
  vector<double> values;
  vector<vector<string>> queries;
  vector<double> expected;

  equations = {{"a", "b"}, {"b", "c"}};
  values = {2.0, 3.0};
  queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  expected = {6.0, 0.5, -1.0, 1.0, -1.0};
  //EXPECT_EQ(expected, sol.calcEquation(equations, values, queries));

  equations = {{"a", "b"}, {"b", "c"}, {"c", "d"}};
  values = {2.0, 3.0, 2.5};
  queries = {{"a", "d"}};
  expected = {15.0};
  //EXPECT_EQ(expected, sol.calcEquation(equations, values, queries));

  equations = {{"a", "b"}, {"c", "b"}};
  values = {3.0, 2.0};
  queries = {{"a", "c"}};
  expected = {1.5};
  EXPECT_EQ(expected, sol.calcEquation(equations, values, queries));

  exit(EXIT_SUCCESS);
}
