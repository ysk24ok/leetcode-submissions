#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    unordered_map<int, size_t> map;
    set<int> s;
    int threshold = nums.size() / 3 + 1;
    for (const auto& num : nums) {
      map[num]++;
      if (map[num] >= threshold) {
        s.insert(num);
      }
    }
  return vector<int>(s.begin(), s.end());
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  vector<int> expected;

  nums = {3,2,3};
  expected = {3};
  EXPECT_EQ(expected, sol.majorityElement(nums));

  nums = {1,1,1,3,3,2,2,2};
  expected = {1,2};
  EXPECT_EQ(expected, sol.majorityElement(nums));

  nums = {3,3,3,3,2};
  expected = {3};
  EXPECT_EQ(expected, sol.majorityElement(nums));

  nums = {1,2,2,3,2,1,1,3};
  expected = {1,2};
  EXPECT_EQ(expected, sol.majorityElement(nums));

  nums = {1,2};
  expected = {1,2};
  EXPECT_EQ(expected, sol.majorityElement(nums));

  exit(EXIT_SUCCESS);
}
