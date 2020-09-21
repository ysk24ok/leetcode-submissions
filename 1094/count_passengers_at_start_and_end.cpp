#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int end_location = 0;
    map<int, int> inc_dec;
    for (const auto& trip : trips) {
      inc_dec[trip[1]] += trip[0];
      inc_dec[trip[2]] -= trip[0];
      end_location = max(end_location, trip[2]);
    }
    int total = 0;
    for (const auto& p : inc_dec) {
      if (inc_dec.find(p.first) == inc_dec.end()) {
        continue;
      }
      total += inc_dec[p.first];
      if (total > capacity) { return false; }
    }
    return true;
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
