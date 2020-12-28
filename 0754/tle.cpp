#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int reachNumber(int target) {
    unordered_map<int, int> map;
    queue<pair<int, size_t>> q; // timestep, position
    q.push({0, 0});
    int ret;
    while (!q.empty()) {
      pair<int, int> elem = q.front();
      q.pop();
      int timestep = elem.first;
      int position = elem.second;
      map[position] = timestep;
      if (map.find(target) != map.end()) {
        ret = map[target];
        break;
      }
      int next_timestep = timestep + 1;
      q.push({next_timestep, position - next_timestep});
      q.push({next_timestep, position + next_timestep});
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int target, expected;

  target = 1, expected = 1;
  EXPECT_EQ(expected, sol.reachNumber(target));

  target = 2, expected = 3;
  EXPECT_EQ(expected, sol.reachNumber(target));

  target = 3, expected = 2;
  EXPECT_EQ(expected, sol.reachNumber(target));

  target = -1000000000, expected = 44723;
  EXPECT_EQ(expected, sol.reachNumber(target));

  exit(EXIT_SUCCESS);
}
