#include <gtest/gtest.h>

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, size_t> map;
    vector<int> ret(2);
    for (size_t i = 0; i < nums.size(); ++i) {
      int diff = target - nums[i];
      if (map.find(diff) != map.end()) {
        ret[0] = i;
        ret[1] = map[diff];
        break;
      }
      map[nums[i]] = i;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums, actual;
  int target;

  nums = {2, 7, 11, 15}, target = 9;
  actual = sol.twoSum(nums, target);
  EXPECT_TRUE((actual[0] == 0 && actual[1] == 1) || (actual[0] == 1 && actual[1] == 0));

  nums = {3, 2, 4}, target = 6;
  actual = sol.twoSum(nums, target);
  EXPECT_TRUE((actual[0] == 1 && actual[1] == 2) || (actual[0] == 2 && actual[1] == 1));

  nums = {3, 3}, target = 6;
  actual = sol.twoSum(nums, target);
  EXPECT_TRUE((actual[0] == 0 && actual[1] == 1) || (actual[0] == 1 && actual[1] == 0));
}
