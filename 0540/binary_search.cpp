#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    size_t start = 0, end = nums.size() - 1;
    while (start < end) {
      size_t mid = (end - start) / 2 + start;
      if (mid % 2 == 1) { mid--; }
      if (nums[mid] != nums[mid+1]) {
        end = mid;
      } else {
        start = mid + 2;
      }
    }
    return nums[start];
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {1,1,2,3,3,4,4,8,8};
  ExpectEqual(2, sol.singleNonDuplicate(nums));
  nums = {3,3,7,7,10,11,11};
  ExpectEqual(10, sol.singleNonDuplicate(nums));
  nums = {1,1,3};
  ExpectEqual(3, sol.singleNonDuplicate(nums));
  nums = {1,3,3};
  ExpectEqual(1, sol.singleNonDuplicate(nums));
  nums = {1,2,2,3,3};
  ExpectEqual(1, sol.singleNonDuplicate(nums));
  nums = {1,1,2,3,3};
  ExpectEqual(2, sol.singleNonDuplicate(nums));
  nums = {1,1,2,2,3};
  ExpectEqual(3, sol.singleNonDuplicate(nums));
  nums = {1,3,3,5,5,7,7};
  ExpectEqual(1, sol.singleNonDuplicate(nums));
  nums = {1,1,2,2,4,4,5,5,9};
  ExpectEqual(9, sol.singleNonDuplicate(nums));
  nums = {1,1,3,3,5,5,7,9,9,11,11};
  ExpectEqual(7, sol.singleNonDuplicate(nums));
}
