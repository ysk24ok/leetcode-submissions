#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> map;
    for (const auto& num : nums) map[num]++;
    int ret = 0;
    for (const auto& pair : map) {
      if (pair.second == 1) ret = pair.first;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {2,2,1};
  assert(sol.singleNumber(nums) == 1);

  nums = {4,1,2,1,2};
  assert(sol.singleNumber(nums) == 4);

  nums = {2};
  assert(sol.singleNumber(nums) == 2);
}
