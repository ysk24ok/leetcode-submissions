#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
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
  int countElements(vector<int>& arr) {
    unordered_map<int, int> map;
    for (const auto& val : arr) { map[val]++; }
    int ret = 0;
    for (const auto& pair : map) {
      if (map.find(pair.first + 1) != map.end()) {
        ret += pair.second;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> arr;

  arr = {1,2,3};
  assert(sol.countElements(arr) == 2);

  arr = {1,1,3,3,5,5,7,7};
  assert(sol.countElements(arr) == 0);

  arr = {1,1,2,2};
  assert(sol.countElements(arr) == 2);

  arr = {1,1,2};
  assert(sol.countElements(arr) == 2);

  arr = {1,3,2,3,5,0};
  assert(sol.countElements(arr) == 3);
}
