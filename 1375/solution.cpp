#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int numTimesAllBlue(vector<int>& light) {
    vector<bool> turned_on(light.size()+1, false);
    int ret = 0;
    int ptr = 1;
    int last = 1;
    for (int& l : light) {
      turned_on[l] = true;
      last = max(l, last);
      ptr = move_ptr(turned_on, ptr, last);
      if (ptr == last) ret++;
    }
    return ret;
  }

  int move_ptr(const vector<bool>& turned_on, int start, int last) {
    int ptr = start;
    for (int i = start; i < last; i++) {
      if (!turned_on[i]) break;
      ptr++;
    }
    return ptr;
  }
};

int main() {
  Solution sol;
  vector<int> light;

  light = {2,1,3,5,4};
  assert(sol.numTimesAllBlue(light) == 3);

  light = {3,2,4,1,5};
  assert(sol.numTimesAllBlue(light) == 2);

  light = {4,1,2,3};
  assert(sol.numTimesAllBlue(light) == 1);

  light = {2,1,4,3,6,5};
  assert(sol.numTimesAllBlue(light) == 3);

  light = {1,2,3,4,5,6};
  assert(sol.numTimesAllBlue(light) == 6);
}
