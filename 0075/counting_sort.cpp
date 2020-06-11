#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int c0 = 0;
    int c1 = 0;
    for (auto& num : nums) {
      if (num == 0) {
        c0++;
        c1++;
      }
      else if (num == 1) c1++;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i < c0) nums[i] = 0;
      else if (c0 <= i && i < c1) nums[i] = 1;
      else nums[i] = 2;
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  vector<int> expected;

  nums = {2,0,2,1,1,0};
  expected = {0,0,1,1,2,2};
  sol.sortColors(nums);
  assert(nums == expected);
}
