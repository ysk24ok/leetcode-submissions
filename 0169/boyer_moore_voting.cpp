#include "gtest/gtest.h"

#include <vector>

using namespace std;

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
  EXPECT_EQ(3, sol.majorityElement(nums));

  nums = {2,2,1,1,1,2,2};
  EXPECT_EQ(2, sol.majorityElement(nums));

  nums = {1};
  EXPECT_EQ(1, sol.majorityElement(nums));
}
