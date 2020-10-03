#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ret = 0;
    unordered_map<int, int> map;
    for (const auto& num : nums) {
      if (k != 0 && map.find(num) == map.end() && map.find(num - k) != map.end()) {
        ret++;
      } else if (k == 0 && map.find(num) != map.end() && map[num] == 1) {
        ret++;
      }
      map[num] += 1;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int k;
  int expected;

  nums = {3, 1, 4, 1, 5}, k = 2;
  expected = 2;
  EXPECT_EQ(expected, sol.findPairs(nums, k));

  nums = {1, 2, 3, 4, 5}, k = 1;
  expected = 4;
  EXPECT_EQ(expected, sol.findPairs(nums, k));

  nums = {1, 3, 1, 5, 4}, k = 0;
  expected = 1;
  EXPECT_EQ(expected, sol.findPairs(nums, k));

  nums = {1, 2, 4, 4, 3, 3, 0, 9, 2, 3}, k = 3;
  expected = 2;
  EXPECT_EQ(expected, sol.findPairs(nums, k));

  nums = {-1, -2, -3}, k = 1;
  expected = 2;
  EXPECT_EQ(expected, sol.findPairs(nums, k));

  nums = {1, 1, 1}, k = 0;
  expected = 1;
  EXPECT_EQ(expected, sol.findPairs(nums, k));

  exit(EXIT_SUCCESS);
}
