#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

// XXX: TLE
// time complexity: O(N^2)
class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    const size_t n = nums.size();
    int ret = 0;
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }
        ret = max(ret, nums[i] ^ nums[j]);
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {3, 10, 5, 25, 2, 8};
  expected = 28;
  EXPECT_EQ(expected, sol.findMaximumXOR(nums));

  exit(EXIT_SUCCESS);
}
