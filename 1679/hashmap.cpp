#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    int ret = 0;
    for (const int& num : nums) {
      int pair = k - num;
      if (counts.find(pair) != counts.end() && counts[pair] > 0) {
        counts[pair]--;
        ret++;
      } else {
        counts[num]++;
      }
    }
    return ret;
  }
};


int main() {
  Solution sol;
  vector<int> nums;
  int k, expected;

  nums = {1, 2, 3, 4}, k = 5, expected = 2;
  EXPECT_EQ(expected, sol.maxOperations(nums, k));

  nums = {3, 1, 3, 4, 3}, k = 6, expected = 1;
  EXPECT_EQ(expected, sol.maxOperations(nums, k));

  exit(EXIT_SUCCESS);
}
