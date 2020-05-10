#include <set>
#include <unordered_map>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    unordered_map<int, set<int>> map;
    for (const auto& edge : edges) {
      map[edge[0]].insert(edge[1]);
      map[edge[1]].insert(edge[0]);
    }
    vector<bool> visited(n, false);
    return dfs(0, visited, map, hasApple);
  }

  int dfs(int node, vector<bool>& visited, const unordered_map<int, set<int>>& map, const vector<bool>& hasApple) {
    if (visited[node]) { return 0; }
    visited[node] = true;
    int ret = 0;
    for (const int& next_node : map.at(node)) {
      ret += dfs(next_node, visited, map, hasApple);
    }
    if (node == 0) { return ret; }
    if (hasApple[node] || (!hasApple[node] && ret > 0)) { ret += 2; }
    return ret;
  }
};

int main() {
  Solution sol;
  int n;
  vector<vector<int>> edges;
  vector<bool> hasApple;

  n = 7;
  edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
  hasApple = {false,false,true,false,true,true,false};
  ExpectEqual(8, sol.minTime(n, edges, hasApple));
  hasApple = {false,false,true,false,false,true,false};
  ExpectEqual(6, sol.minTime(n, edges, hasApple));
  hasApple = {false,false,false,false,false,false,false};
  ExpectEqual(0, sol.minTime(n, edges, hasApple));

  //    0
  //   / \
  //  1   3
  //   \
  //    2
  n = 4;
  edges = {{0,1},{1,2},{0,3}};
  hasApple = {true,true,true,true};
  ExpectEqual(6, sol.minTime(n, edges, hasApple));
}
