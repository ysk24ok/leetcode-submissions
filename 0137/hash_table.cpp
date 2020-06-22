#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, size_t> map;
    for (const int& num : nums) { map[num]++; }
    int ret = 0;
    for (const auto& p : map) {
      if (p.second == 1) {
        ret = p.first;
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {2,2,3,2};
  expected = 3;
  EXPECT_EQ(expected, sol.singleNumber(nums));

  nums = {0,1,0,1,0,1,99};
  expected = 99;
  EXPECT_EQ(expected, sol.singleNumber(nums));

  exit(EXIT_SUCCESS);
}
