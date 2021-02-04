#include <gtest/gtest.h>

#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findLHS(vector<int>& nums) {
    map<int, size_t> counts;
    for (const int& num : nums) {
      counts[num]++;
    }
    size_t ret = 0;
    for (const pair<int, size_t>& p : counts) {
      if (counts.find(p.first + 1) == counts.end()) {
        continue;
      }
      ret = max(p.second + counts[p.first + 1], ret);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {1, 3, 2, 2, 5, 2, 3, 7}, expected = 5;
  EXPECT_EQ(expected, sol.findLHS(nums));

  nums = {1, 2, 3, 4}, expected = 2;
  EXPECT_EQ(expected, sol.findLHS(nums));

  nums = {1, 1, 1, 1}, expected = 0;
  EXPECT_EQ(expected, sol.findLHS(nums));

  exit(EXIT_SUCCESS);
}
