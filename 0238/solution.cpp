#include <iostream>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    size_t n = nums.size();
    vector<int> left(n, 1);
    for (size_t i = 1; i < n; ++i) {
      left[i] = left[i-1] * nums[i-1];
    }
    vector<int> right(n, 1);
    for (size_t i = n - 1; i > 0; --i) {
      right[i-1] = right[i] * nums[i];
    }
    vector<int> ret(n);
    for (size_t i = 0; i < n; ++i) {
      ret[i] = left[i] * right[i];
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums, got, expected;

  //        {1,2,3,4}
  // left:  {1,    1,  1*2,1*2*3}
  // right: {2*3*4,3*4,4,  1    }
  nums = {1,2,3,4};
  got = sol.productExceptSelf(nums);
  expected = {24,12,8,6};
  ExpectVectorEqual(expected, got);
}
