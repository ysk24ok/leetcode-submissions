#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int MAX_LOCATION = 1000;

// N is the number of trips and M is the number of locations
// time complexity: O(N+M)
// space complexity: O(M)
class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> dp(MAX_LOCATION, 0);
    bool ret = true;
    // It is more efficient to track getting on and off of passengers
    // compared with counting the number of passengers at all locations
    for (auto& trip : trips) {
      dp[trip[1]] += trip[0];
      dp[trip[2]] -= trip[0];
    }
    for (auto& num_passengers : dp) {
      capacity -= num_passengers;
      if (capacity < 0) return false;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> trips;
  int capacity;

  trips = {};
  capacity = 2;
  assert(sol.carPooling(trips, capacity));

  trips = {{2,1,5},{3,3,7}};
  capacity = 4;
  assert(!sol.carPooling(trips, capacity));

  trips = {{2,1,5},{3,3,7}};
  capacity = 5;
  assert(sol.carPooling(trips, capacity));

  trips = {{2,1,5},{3,5,7}};
  capacity = 3;
  assert(sol.carPooling(trips, capacity));

  trips = {{3,2,7},{3,7,9},{8,3,9}};
  capacity = 11;
  assert(sol.carPooling(trips, capacity));
}
