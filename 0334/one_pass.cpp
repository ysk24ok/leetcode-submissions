#include <gtest/gtest.h>

#include <cstdlib>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int first = numeric_limits<int>::max(), second = numeric_limits<int>::max();
    for (const int& num : nums) {
      if (num <= first) { first = num; }
      else if (num <= second) { second = num; }
      else return true;
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  bool expected;

  nums = {1, 2, 3, 4, 5};
  expected = true;
  EXPECT_EQ(expected, sol.increasingTriplet(nums));

  nums = {5, 4, 3, 2, 1};
  expected = false;
  EXPECT_EQ(expected, sol.increasingTriplet(nums));

  nums = {2, 1, 5, 0, 4, 6};
  expected = true;
  EXPECT_EQ(expected, sol.increasingTriplet(nums));

  nums = {1, 2, -10, -8, -7};
  expected = true;
  EXPECT_EQ(expected, sol.increasingTriplet(nums));

  exit(EXIT_SUCCESS);
}
