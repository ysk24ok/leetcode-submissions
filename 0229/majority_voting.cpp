#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// time complexity: O(2N) -> O(N)
// memory complexity: O(1)
class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    vector<int> ret;
    for (auto& num : nums) {
      if (num == candidate1) {
        count1++;
      } else if (num == candidate2) {
        count2++;
      } else if (count1 == 0) {
        candidate1 = num;
        count1++;
      } else if (count2 == 0) {
        candidate2 = num;
        count2++;
      } else {
        count1--;
        count2--;
      }
    }
    count1 = 0, count2 = 0;
    for (auto& num : nums) {
      if (num == candidate1) {
        count1++;
      } else if (num == candidate2) {
        count2++;
      }
    }
    if (count1 > nums.size() / 3) ret.push_back(candidate1);
    if (count2 > nums.size() / 3) ret.push_back(candidate2);
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  vector<int> got;
  vector<int> expected;

  nums = {3,2,3};
  expected = {3};
  got = sol.majorityElement(nums);
  assert(got == expected);

  nums = {1,1,1,3,3,2,2,2};
  expected = {1,2};
  got = sol.majorityElement(nums);
  assert(got == expected);

  nums = {3,3,3,3,2};
  expected = {3};
  got = sol.majorityElement(nums);
  assert(got == expected);

  nums = {1,2,2,3,2,1,1,3};
  expected = {1,2};
  got = sol.majorityElement(nums);
  assert(got == expected);

  nums = {1,2};
  expected = {1,2};
  got = sol.majorityElement(nums);
  assert(got == expected);
}
