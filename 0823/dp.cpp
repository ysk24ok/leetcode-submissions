#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int mod = 1e9 + 7;

class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    unordered_map<int, int> val2idx;
    for (size_t i = 0; i < arr.size(); ++i) {
      val2idx[arr[i]] = i;
    }
    vector<long> dp(arr.size(), 1);
    for (size_t parent_idx = 0; parent_idx < arr.size(); ++parent_idx) {
      for (size_t child_idx = 0; child_idx < parent_idx; ++child_idx) {
        if (arr[parent_idx] % arr[child_idx] != 0) {
          continue;
        }
        int another_child_val = arr[parent_idx] / arr[child_idx];
        if (val2idx.find(another_child_val) != val2idx.end()) {
          int another_child_idx = val2idx[another_child_val];
          dp[parent_idx] += dp[child_idx] * dp[another_child_idx] % mod;
          dp[parent_idx] %= mod;
        }
      }
    }
    int ret = 0;
    for (const auto& val : dp) {
      ret += val;
      ret %= mod;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> arr;
  int expected;

  arr = {2, 4}, expected = 3;
  EXPECT_EQ(expected, sol.numFactoredBinaryTrees(arr));

  arr = {2, 4, 5, 10}, expected = 7;
  EXPECT_EQ(expected, sol.numFactoredBinaryTrees(arr));

  exit(EXIT_SUCCESS);
}
