#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLucky(vector<int>& arr) {
    unordered_map<int, int> map;
    for (const auto& val : arr) {
      map[val] += 1;
    }
    int ret = -1;
    for (const auto& pair : map) {
      if (pair.first == pair.second)
        ret = max(ret, pair.first);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> arr;

  arr = {2,2,3,4};
  assert(sol.findLucky(arr) == 2);

  arr = {1,2,2,3,3,3};
  assert(sol.findLucky(arr) == 3);

  arr = {2,2,2,3,3};
  assert(sol.findLucky(arr) == -1);

  arr = {5};
  assert(sol.findLucky(arr) == -1);

  arr = {7,7,7,7,7,7,7};
  assert(sol.findLucky(arr) == 7);
}
