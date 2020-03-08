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
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    if (n == 1) return 0;
    unordered_map<int, bool> map;
    for (int i = 0; i < n; i++) {
      if (i == headID) continue;
      int mid = manager[i];
      if (map.find(i) == map.end()) {
        map[i] = false;
      }
      map[mid] = true;
    }
    //int ret = numeric_limits<int>::max();
    int ret = 0;
    for (auto& it : map) {
      int eid = it.first;
      const bool& has_subordinate = it.second;
      if (has_subordinate) continue;
      int time = 0;
      while (true) {
        const int& mid = manager[eid];
        if (mid == -1) break;
        time += informTime[mid];
        eid = mid;
      }
      //ret = min(ret, time);
      ret = max(ret, time);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int n;
  int headID;
  vector<int> manager;
  vector<int> informTime;

  n = 1;
  headID = 0;
  manager = {-1};
  informTime = {0};
  assert(sol.numOfMinutes(n, headID, manager, informTime) == 0);

  n = 6;
  headID = 2;
  manager = {2,2,-1,2,2,2};
  informTime = {0,0,1,0,0,0};
  assert(sol.numOfMinutes(n, headID, manager, informTime) == 1);

  n = 7;
  headID = 6;
  manager = {1,2,3,4,5,6,-1};
  informTime = {0,6,5,4,3,2,1};
  assert(sol.numOfMinutes(n, headID, manager, informTime) == 21);

  n = 15;
  headID = 0;
  manager = {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6};
  informTime = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
  assert(sol.numOfMinutes(n, headID, manager, informTime) == 3);

  n = 4;
  headID = 2;
  manager = {3,3,-1,2};
  informTime = {0,0,162,914};
  assert(sol.numOfMinutes(n, headID, manager, informTime) == 1076);

  n = 8;
  headID = 0;
  manager = {-1,5,0,6,7,0,0,0};
  informTime = {89,0,0,0,0,523,241,519};
  assert(sol.numOfMinutes(n, headID, manager, informTime) == 612);
}
