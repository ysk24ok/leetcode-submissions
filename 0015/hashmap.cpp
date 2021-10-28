#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    if (nums.size() < 3) {
      return ret;
    }
    sort(nums.begin(), nums.end());
    const size_t n = nums.size();
    unordered_map<int, size_t> indices;
    for (size_t i = 0; i < n; ++i) {
      indices[nums[i]] = i;
    }
    for (size_t i = 0; i < n - 2; ++i) {
      for (size_t j = i + 1; j < n - 1; ++j) {
        int target = 0 - nums[i] - nums[j];
        if (indices.find(target) != indices.end() && j < indices[target]) { 
          ret.push_back({nums[i], nums[j], target});
        }
        j = indices[nums[j]];  // to avoid duplicates
      }
      i = indices[nums[i]]; // to avoid duplicates
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  vector<vector<int>> expected;

  nums = {-1, 0, 1, 2, -1, -4}, expected = {{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(sol.threeSum(nums), expected);

  nums = {0, 0, 0, 0}, expected = {{0, 0, 0}};
  EXPECT_EQ(sol.threeSum(nums), expected);

  exit(EXIT_SUCCESS);
}
