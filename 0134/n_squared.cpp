#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    for (int start = 0; start < gas.size(); ++start) {
      if (canStartFrom(start, gas, cost)) {
        return start;
      }
    }
    return -1;
  }

  bool canStartFrom(int start, const vector<int>& gas, const vector<int>& cost) {
    const int n = gas.size();
    int curr_gas = 0;
    int curr_station_idx;
    for (int i = start; i < start + n; ++i) {
      int curr_station_idx = i;
      if (curr_station_idx >= n) { curr_station_idx -= n; }
      curr_gas += (gas[curr_station_idx] - cost[curr_station_idx]);
      if (curr_gas < 0) { return false; }
    }
    return true;
  }
};

int main() {
  Solution sol;
  vector<int> gas, cost;
  int expected;

  gas = {1, 2, 3, 4, 5};
  cost = {3, 4, 5, 1, 2};
  expected = 3;
  EXPECT_EQ(expected, sol.canCompleteCircuit(gas, cost));

  gas = {2, 3, 4};
  cost = {3, 4, 3};
  expected = -1;
  EXPECT_EQ(expected, sol.canCompleteCircuit(gas, cost));

  exit(EXIT_SUCCESS);
}
