#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<int> distance(n, numeric_limits<int>::max());
    distance[src] = 0;
    for (int i = 0; i <= K; ++i) {
      vector<int> new_distance(distance);
      for (const auto& flight : flights) {
        const int& source = flight[0];
        const int& dest = flight[1];
        const int& dist = flight[2];
        if (distance[source] != numeric_limits<int>::max()) {
          new_distance[dest] = min(distance[source] + dist, new_distance[dest]);
        } else {
          new_distance[dest] = min(distance[source], new_distance[dest]);
        }
      }
      distance = new_distance;
    }
    return distance[dst] != numeric_limits<int>::max() ? distance[dst] : -1;
  }
};

int main() {
  Solution sol;
  int n, src, dst, K;
  vector<vector<int>> flights;

  n = 3, src = 0, dst = 2, K = 1;
  flights = {{0,1,100},{1,2,100},{0,2,500}};
  assert(sol.findCheapestPrice(n, flights, src, dst, K) == 200);

  n = 3, src = 0, dst = 2, K = 0;
  flights = {{0,1,100},{1,2,100},{0,2,500}};
  assert(sol.findCheapestPrice(n, flights, src, dst, K) == 500);

  n = 3, src = 0, dst = 1, K = 1;
  flights = {{1,0,100},{0,2,100},{1,2,100}};
  assert(sol.findCheapestPrice(n, flights, src, dst, K) == -1);
}
