#include <cstdlib>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    unordered_map<int, vector<pair<int, int>>> map;
    for (const auto& flight : flights) {
      const int& source = flight[0];
      const int& dest = flight[1];
      const int& dist = flight[2];
      map[source].push_back({dest, dist});
    }
    auto greater = [](const vector<int>& left, const vector<int>& right) {
      return left[2] > right[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(greater)> pq(greater);
    // current node, number of stops, distance from source node
    pq.push({src, -1, 0});
    while (!pq.empty()) {
      vector<int> edge = pq.top();
      const int& source = edge[0];
      const int& num_stops = edge[1];
      const int& total_dist = edge[2];
      if (source == dst) { return total_dist; }
      pq.pop();
      for (const auto& node : map[source]) {
        const int& dest = node.first;
        const int& dist = node.second;
        const int new_dist = total_dist + dist;
        if (num_stops < K) {
          pq.push({dest, num_stops + 1, new_dist});
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  int n, src, dst, K, expected;
  vector<vector<int>> flights;

  n = 3, src = 0, dst = 2, K = 1, expected = 200;
  flights = {{0,1,100},{1,2,100},{0,2,500}};
  EXPECT_EQ(expected, sol.findCheapestPrice(n, flights, src, dst, K));

  n = 3, src = 0, dst = 2, K = 0, expected = 500;
  flights = {{0,1,100},{1,2,100},{0,2,500}};
  EXPECT_EQ(expected, sol.findCheapestPrice(n, flights, src, dst, K));

  n = 3, src = 0, dst = 1, K = 1, expected = -1;
  flights = {{1,0,100},{0,2,100},{1,2,100}};
  EXPECT_EQ(expected, sol.findCheapestPrice(n, flights, src, dst, K));

  // shortest path to 2
  //    5    1    1
  // 0 -> 1 -> 4 -> 2
  //
  // shortest path to 1
  //    2    2
  // 0 -> 3 -> 1
  n = 5, src = 0, dst = 2, K = 2, expected = 7;
  flights = {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
  EXPECT_EQ(expected, sol.findCheapestPrice(n, flights, src, dst, K));

  exit(EXIT_SUCCESS);
}
