#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    // phase1
    // tortoise moves F + a
    // hare moves F + a + nC
    // => 2(F + a) = F + a + nC
    // => F + a = nC
    int tortoise = nums[0], hare = nums[0];
    tortoise = nums[tortoise];
    hare = nums[nums[hare]];
    while (tortoise != hare) {
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
    }
    // phase2
    // tortoise moves F
    // hare moves F + a + nC + F = (n+1)C + F -> F
    tortoise = nums[0];
    while (tortoise != hare) {
      tortoise = nums[tortoise];
      hare = nums[hare];
    }
    return tortoise;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {1,3,4,2,2};
  expected = 2;
  EXPECT_EQ(expected, sol.findDuplicate(nums));

  nums = {3,1,3,4,2};
  expected = 3;
  EXPECT_EQ(expected, sol.findDuplicate(nums));

  exit(EXIT_SUCCESS);
}
