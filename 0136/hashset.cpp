#include <gtest/gtest.h>

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_set<int> set;
    for (const auto& num : nums) {
      if (set.find(num) != set.end()) {
        set.erase(num);
      } else {
        set.insert(num);
      }
    }
    return *set.begin();
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {2,2,1}, expected = 1;
  EXPECT_EQ(sol.singleNumber(nums), expected);

  nums = {4,1,2,1,2}, expected = 4;
  EXPECT_EQ(sol.singleNumber(nums), expected);

  nums = {2}, expected = 2;
  EXPECT_EQ(sol.singleNumber(nums), expected);
}
