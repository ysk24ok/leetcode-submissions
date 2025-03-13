#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    size_t j, k;
    for (size_t i = 0; i < nums.size() - 2; i++) {
      if (0 < i && nums[i - 1] == nums[i]) { continue; }
      j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum > 0) {
          k--;
        } else if (sum < 0) {
          j++;
        } else {
          ret.push_back({nums[i], nums[j++], nums[k--]});
          while (j < k && nums[k] == nums[k + 1]) { k--; }
          while (j < k && nums[j - 1] == nums[j]) { j++; }
        }
      }
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
