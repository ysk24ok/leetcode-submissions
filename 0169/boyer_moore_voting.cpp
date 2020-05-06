#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;
    for (size_t i = 1, m = nums.size(); i < m; ++i) {
      if (count == 0) {
        candidate = nums[i];
      }
      count += (nums[i] == candidate) ? 1 : -1;
    }
    return candidate;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {3,2,3};
  ExpectEqual(3, sol.majorityElement(nums));

  nums = {2,2,1,1,1,2,2};
  ExpectEqual(2, sol.majorityElement(nums));

  nums = {1};
  ExpectEqual(1, sol.majorityElement(nums));
}
