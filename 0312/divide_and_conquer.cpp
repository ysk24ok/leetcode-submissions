#include <gtest/gtest.h>

#include <vector>

using namespace std;

constexpr int N = 500;
int memo[N+2+1][N+2+1];

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    vector<int> nums_new(nums.size() + 2, 1);
    for (size_t i = 0; i < nums.size(); ++i) {
      nums_new[i + 1] = nums[i];
    }
    memset(memo, 0, sizeof(memo));
    return divideAndConquer(nums_new, 0, nums_new.size()-1);
  }

 private:
  int divideAndConquer(const vector<int>& nums, size_t left, size_t right) {
    // memo[left][right] is the maximum score
    // when balloons at (left, right) (not [left, right]) are bursted.
    if (left + 1 == right) {
      return 0;
    }
    if (memo[left][right] > 0) {
      return memo[left][right];
    }
    int ret = 0;
    for (size_t i = left + 1; i < right; ++i) {
      ret = max(
        ret,
        // Since i-th balloon is bursted
        // after balloons at (left, i) and (i, right) are bursted,
        // nums[left] * nums[i] * nums[right] is added.
        nums[left] * nums[i] * nums[right] + 
          divideAndConquer(nums, left, i) +
          divideAndConquer(nums, i, right)
      );
    }
    memo[left][right] = ret;
    return memo[left][right];
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {3, 1, 5, 8}, expected = 167;
  EXPECT_EQ(sol.maxCoins(nums), expected);

  nums = {1, 5}, expected = 10;
  EXPECT_EQ(sol.maxCoins(nums), expected);

  exit(EXIT_SUCCESS);
}
