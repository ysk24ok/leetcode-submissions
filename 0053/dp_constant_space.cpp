#include <algorithm>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) { return 0; }
    int total_max = numeric_limits<int>::min();
    int current_max = 0;
    for (const auto& num : nums) {
      current_max = max(current_max, 0) + num;
      total_max = max(total_max, current_max);
    }
    return total_max;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {-2,1,-3,4,-1,2,1,-5,4};
  EXPECT_EQ(6, sol.maxSubArray(nums));

  nums = {};
  EXPECT_EQ(0, sol.maxSubArray(nums));

  nums = {-1};
  EXPECT_EQ(-1, sol.maxSubArray(nums));
}
