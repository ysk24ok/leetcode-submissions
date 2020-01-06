#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, unordered_map<string, double>> graph;
    for (size_t i = 0; i < equations.size(); i++) {
      string& s0 = equations[i][0];
      string& s1 = equations[i][1];
      graph[s0][s0] = 1.0;
      graph[s1][s1] = 1.0;
      graph[s0][s1] = values[i];
      graph[s1][s0] = 1.0 / values[i];
    }
    vector<double> ret(queries.size());
    for (size_t i = 0; i < queries.size(); i++) {
      ret[i] = dfs(graph, queries[i][0], queries[i][1], {});
    }
    return ret;
  }

  double dfs(const unordered_map<string, unordered_map<string, double>>& graph, const string& s0, const string& s1, const unordered_set<string>& set) {
    auto search = graph.find(s0);
    if (search == graph.end()) return -1;
    for (auto& pair : search->second) {
      if (set.find(pair.first) != set.end()) continue;
      else if (pair.first == s1) return pair.second;
      else {
        unordered_set<string> set_copied = set;
        set_copied.insert(pair.first);
        double got = dfs(graph, pair.first, s1, set_copied);
        if (got != -1) return got * pair.second;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<vector<string>> equations;
  vector<double> values, got, expected;
  vector<vector<string>> queries;

  equations = {{"a","b"},{"b","c"}};
  values = {2.0,3.0};
  queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
  got = sol.calcEquation(equations, values, queries);
  expected = {6.0,0.5,-1.0,1.0,-1.0};
  assert(got == expected);

  equations = {{"a","b"},{"b","c"},{"c","d"}};
  values = {2.0,3.0,2.5};
  queries = {{"a","d"}};
  got = sol.calcEquation(equations, values, queries);
  expected = {15.0};
  assert(got == expected);

  equations = {{"a","b"},{"c","b"}};
  values = {3.0,2.0};
  queries = {{"a","c"}};
  got = sol.calcEquation(equations, values, queries);
  expected = {1.5};
  assert(got == expected);
}
