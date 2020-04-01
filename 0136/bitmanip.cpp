#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (const auto& num : nums) ret ^= num;
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
