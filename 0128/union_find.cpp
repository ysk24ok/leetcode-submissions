#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> map;
    for (auto& num : nums) {
      if (map.find(num) != map.end()) continue;
      if (map.find(num-1) != map.end()) map[num] = num-1;
      else map[num] = num;
      if (map.find(num+1) != map.end()) map[num+1] = num;
    }
    for (auto& pair : map) {
      set_root(map, pair.first);
    }
    unordered_map<int, int> count;
    int ret = 0;
    for (auto& pair : map) {
      int root = pair.second;
      if (count.find(root) == count.end()) count[root] = 0;
      count[root] += 1;
      ret = max(ret, count[root]);
    }
    return ret;
  }

  int set_root(unordered_map<int, int>& map, int num) {
    int parent = map[num];
    if (num == parent) return num;
    else {
      int root = set_root(map, parent);
      map[num] = root;
      return root;
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {100, 4, 200, 1, 3, 2};
  assert(sol.longestConsecutive(nums) == 4);

  nums = {7, 1, 5, 3};
  assert(sol.longestConsecutive(nums) == 1);

  nums = {0, -1};
  assert(sol.longestConsecutive(nums) == 2);
}
