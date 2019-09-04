#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int max_distance = -1;
    int pre_seated_idx = -1;
    for (int i = 0; i < seats.size(); i++) {
      if (seats[i] == 0) continue;
      if (pre_seated_idx != -1) {
        max_distance = max((i - pre_seated_idx) / 2, max_distance);
      // when first 1 appears
      } else {
        max_distance = i;
      }
      pre_seated_idx = i;
    }
    // when last index is 0
    int last_idx = seats.size() - 1;
    if (seats[last_idx] == 0) {
      max_distance = max(last_idx - pre_seated_idx, max_distance);
    }
    return max_distance;
  }
};

int main() {
  Solution sol;
  vector<int> v;
  v = {1, 0, 0, 0, 1, 0, 1};
  assert(sol.maxDistToClosest(v) == 2);

  v = {1, 0, 0, 0};
  assert(sol.maxDistToClosest(v) == 3);

  v = {0, 1};
  assert(sol.maxDistToClosest(v) == 1);

  v = {1, 0};
  assert(sol.maxDistToClosest(v) == 1);

  v = {1, 0, 0, 1};
  assert(sol.maxDistToClosest(v) == 1);

  v = {0, 0, 0, 1};
  assert(sol.maxDistToClosest(v) == 3);
}
