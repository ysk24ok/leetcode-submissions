#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visited(rooms.size());
    dfs(rooms, visited, 0);
    return all_of(visited.begin(), visited.end(), [] (bool v) { return v; });
  }

  void dfs(const vector<vector<int>>& rooms, vector<bool>& visited, int room) {
    if (visited[room]) {
      return;
    }
    visited[room] = true;
    for (const int next_room : rooms[room]) {
      dfs(rooms, visited, next_room);
    }
  }
};

int main() {
  Solution sol;
  vector<vector<int>> rooms;
  bool expected;

  rooms = {{1}, {2}, {3}, {}}, expected = true;
  EXPECT_EQ(expected, sol.canVisitAllRooms(rooms));

  rooms = {{1, 3}, {3, 0, 1}, {2}, {0}}, expected = false;
  EXPECT_EQ(expected, sol.canVisitAllRooms(rooms));

  exit(EXIT_SUCCESS);
}
