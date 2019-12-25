#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> map;
    int balance = 0;
    int ret = 0;
    map[0] = -1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) balance++;
      else balance--;
      if (map.find(balance) != map.end()) {
        ret = max(ret, i - map[balance]);
      } else {
        map[balance] = i;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {0,1};
  assert(sol.findMaxLength(nums) == 2);

  nums = {0,1,0};
  assert(sol.findMaxLength(nums) == 2);

  nums = {0,0,1,0,0};
  assert(sol.findMaxLength(nums) == 2);

  nums = {0,0,1,0,0,1,1,1};
  assert(sol.findMaxLength(nums) == 8);

  nums = {1,1,1,0,1,0,0,1};
  assert(sol.findMaxLength(nums) == 6);

  nums = {0,1,1,0,1,1,1,0};
  assert(sol.findMaxLength(nums) == 4);

  nums = {};
  assert(sol.findMaxLength(nums) == 0);
}
