#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    int num_i = nums[0];
    for (size_t j = 1; j < nums.size(); ++j) {
      for (size_t k = j + 1; k < nums.size(); ++k) {
        if (num_i < nums[k] && nums[k] < nums[j]) {
          return true;
        }
      }
      num_i = min(num_i, nums[j]);
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> nums;

  nums = {1, 2, 3, 4};
  EXPECT_FALSE(sol.find132pattern(nums));

  nums = {3, 1, 4, 2};
  EXPECT_TRUE(sol.find132pattern(nums));

  nums = {-1, 3, 2, 0};
  EXPECT_TRUE(sol.find132pattern(nums));

  nums = {3, 5, 0, 3, 4};
  EXPECT_TRUE(sol.find132pattern(nums));

  exit(EXIT_SUCCESS);
}
