#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> graph;
    for (const auto& prerequisite : prerequisites) {
      graph[prerequisite[1]].push_back(prerequisite[0]);
    }
    vector<int> visited(numCourses, false);
    for (int i = 0; i < numCourses; ++i) {
      if (!dfs(graph, visited, i)) { return false; }
    }
    return true;
  }

  bool dfs(unordered_map<int, vector<int>>& graph, vector<int>& visited, int node) {
    if (visited[node]) { return false; }
    for (const int& next_node : graph[node]) {
      visited[node] = true;
      if (!dfs(graph, visited, next_node)) { return false; }
      visited[node] = false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  int num_courses;
  vector<vector<int>> prerequisites;

  // 0 -> 1
  num_courses = 2;
  prerequisites = {{1,0}};
  EXPECT_TRUE(sol.canFinish(num_courses, prerequisites));

  // 0 -> 1
  // 1 -> 0
  num_courses = 2;
  prerequisites = {{1,0},{0,1}};
  EXPECT_FALSE(sol.canFinish(num_courses, prerequisites));

  // 2 -> 1
  // 1 -> 0
  num_courses = 3;
  prerequisites = {{1,2},{0,1}};
  EXPECT_TRUE(sol.canFinish(num_courses, prerequisites));

  // 2 -> 0
  // 1 -> 0
  num_courses = 3;
  prerequisites = {{0,2},{0,1}};
  EXPECT_TRUE(sol.canFinish(num_courses, prerequisites));

  // 0 -> 2
  // 0 -> 1
  num_courses = 3;
  prerequisites = {{2,0},{1,0}};
  EXPECT_TRUE(sol.canFinish(num_courses, prerequisites));

  // 0 -> 1 -> 2 -> 0
  num_courses = 3;
  prerequisites = {{1,0},{0,2},{2,1}};
  EXPECT_FALSE(sol.canFinish(num_courses, prerequisites));

  // 2 -> 1
  // 1 -> 0
  // 2 -> 0
  num_courses = 3;
  prerequisites = {{0,1},{0,2},{1,2}};
  EXPECT_TRUE(sol.canFinish(num_courses, prerequisites));

  // 0 -> 2 -> 3
  // 0 -> 1
  // 1 -> 3
  // 3 -> 1
  num_courses = 4;
  prerequisites = {{2,0},{1,0},{3,1},{3,2},{1,3}};
  EXPECT_FALSE(sol.canFinish(num_courses, prerequisites));

  // 0 -> 1
  // 2 -> 0,3
  // 3 -> 0
  // 4 -> 2
  // 5 -> 2,4
  // 6 -> 5
  num_courses = 7;
  prerequisites = {{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}};
  EXPECT_TRUE(sol.canFinish(num_courses, prerequisites));

  exit(EXIT_SUCCESS);
}
