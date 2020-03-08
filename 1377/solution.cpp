#include <cassert>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    unordered_map<int, vector<int>> moves;
    for (auto& edge : edges) {
      if (moves.find(edge[0]) == moves.end()) {
        moves[edge[0]] = {};
      }
      moves[edge[0]].push_back(edge[1]);
      moves[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n+1, false);
    queue<tuple<int, double, int>> q;
    int cur_node = 1;
    size_t size = moves[cur_node].size();
    if (size != 0) {
      for (int& next_node : moves[cur_node]) {
        q.push({next_node, 1.0f / size, 1});
      }
    } else {
      q.push({cur_node, 1.0f, 1});
    }
    visited[1] = true;
    double ret = 0;
    while (!q.empty()) {
      const tuple<int, double, int> p = q.front();
      q.pop();
      const int& cur_node = get<0>(p);
      const double& prob = get<1>(p);
      const int& cur_time = get<2>(p);
      if (cur_time == t) {
        if (cur_node == target) {
          ret = prob;
          break;
        }
        continue;
      }
      visited[cur_node] = true;
      vector<int> next_nodes;
      for (int& next_node : moves[cur_node]) {
        if (visited[next_node]) continue;
        next_nodes.push_back(next_node);
      }
      size_t size = next_nodes.size();
      if (size == 0) {
        q.push({cur_node, prob, cur_time+1});
      } else {
        for (int& next_node : next_nodes) {
          q.push({next_node, prob / size, cur_time+1});
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int n, t, target;
  vector<vector<int>> edges;
  double expected;
  double epsilon = 0.000001;

  n = 7, t = 2, target = 4;
  edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
  expected = 0.166667;
  assert(abs(sol.frogPosition(n, edges, t, target) - expected) <= epsilon);

  n = 7, t = 1, target = 7;
  edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
  expected = 0.333333;
  assert(abs(sol.frogPosition(n, edges, t, target) - expected) <= epsilon);

  n = 7, t = 20, target = 6;
  edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
  expected = 0.166667;
  assert(abs(sol.frogPosition(n, edges, t, target) - expected) <= epsilon);

  n = 3, t = 1, target = 2;
  edges = {{2,1},{3,2}};
  assert(sol.frogPosition(n, edges, t, target) == 1.0f);

  n = 8, t = 7, target = 7;
  edges = {{2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7}};
  assert(sol.frogPosition(n, edges, t, target) == 0.0f);

  n = 1, t = 1, target = 1;
  edges = {};
  assert(sol.frogPosition(n, edges, t, target) == 1.0f);

  n = 3, t = 1, target = 2;
  edges = {{2,3}};
  assert(sol.frogPosition(n, edges, t, target) == 0.0f);
}
