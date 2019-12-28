#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    int half_size = nums.size() / 2;
    for (auto& n : nums) {
      if (map.find(n) == map.end()) {
        map[n] = 0;
      }
      map[n]++;
      if (map[n] > half_size) return n;
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {3,2,3};
  assert(sol.majorityElement(nums) == 3);

  nums = {2,2,1,1,1,2,2};
  assert(sol.majorityElement(nums) == 2);

  nums = {1};
  assert(sol.majorityElement(nums) == 1);
}
