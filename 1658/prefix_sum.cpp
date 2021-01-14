#include <gtest/gtest.h>

#include <cstdlib>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/discuss/935935/Java-Detailed-Explanation-O(N)-Prefix-SumMap-Longest-Target-Sub-Array
// nums = {1, 2, 3, 4, 5, 6}, x = 14
//  -> {1, 2}: left subarray, {3, 4}: middle subarray, {5, 6}: right subarray
class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int sum = 0;    // sum of the left and the middle subarrays
    int target = accumulate(nums.begin(), nums.end(), 0) - x;   // sum of the middle subarray
    if (target == 0) { return nums.size(); }
    size_t length = 0;    // the length of the middle subarray
    unordered_map<int, size_t> prefix_sum;
    prefix_sum[0] = -1;
    for (size_t i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      int sum_of_left_subarray = sum - target;
      if (prefix_sum.find(sum_of_left_subarray) != prefix_sum.end()) {
        length = max(i - prefix_sum[sum_of_left_subarray], length);
      }
      prefix_sum[sum] = i;
    }
    return length != 0 ? nums.size() - length : -1;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int x, expected;

  nums = {1, 1, 4, 2, 3}, x = 5, expected = 2;
  EXPECT_EQ(expected, sol.minOperations(nums, x));

  nums = {5, 6, 7, 8, 9}, x = 4, expected = -1;
  EXPECT_EQ(expected, sol.minOperations(nums, x));

  nums = {3, 2, 20, 1, 1, 3}, x = 10, expected = 5;
  EXPECT_EQ(expected, sol.minOperations(nums, x));

  nums = {1, 2, 3, 4, 5}, x = 15, expected = 5;
  EXPECT_EQ(expected, sol.minOperations(nums, x));

  exit(EXIT_SUCCESS);
}
