#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> q;
    int current_fuel = startFuel;
    int ret = 0;
    int prev_miles = 0;
    stations.push_back({target, 0});
    for (const auto& station : stations) {
      const int& miles = station[0];
      const int& fuel = station[1];
      current_fuel -= (miles - prev_miles);
      prev_miles = miles;
      while (current_fuel < 0) {
        if (q.empty()) return -1;
        current_fuel += q.top();
        q.pop();
        ret++;
      }
      q.push(fuel);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int target, startFuel;
  vector<vector<int>> stations;

  target = 1;
  startFuel = 1;
  stations = {};
  assert(sol.minRefuelStops(target, startFuel, stations) == 0);

  target = 100;
  startFuel = 10;
  stations = {{10,10}};
  assert(sol.minRefuelStops(target, startFuel, stations) == -1);

  target = 100;
  startFuel = 10;
  stations = {{10,60},{20,30},{30,30},{60,40}};
  assert(sol.minRefuelStops(target, startFuel, stations) == 2);

  target = 100;
  startFuel = 50;
  stations = {{50,50}};
  assert(sol.minRefuelStops(target, startFuel, stations) == 1);

  target = 100;
  startFuel = 1;
  stations = {{10,100}};
  assert(sol.minRefuelStops(target, startFuel, stations) == -1);

  target = 1000;
  startFuel = 83;
  stations = {{25,27},{36,187},{140,186},{378,6},{492,202},{517,89},{579,234},{673,86},{808,53},{954,49}};
  assert(sol.minRefuelStops(target, startFuel, stations) == -1);
}
