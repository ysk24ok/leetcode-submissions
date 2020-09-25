#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> strs(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      strs[i] = to_string(nums[i]);
    }
    auto comp = [](const string& left, const string& right) {
      return left + right > right + left;
    };
    sort(strs.begin(), strs.end(), comp);
    string ret;
    for (const auto& str : strs) {
      ret += str;
    }
    while (ret[0] == '0' && ret.size() > 1) {
      ret.erase(0, 1);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  string expected;

  nums = {10, 2};
  expected = "210";
  EXPECT_EQ(expected, sol.largestNumber(nums));

  nums = {3, 30, 34, 5, 9};
  expected = "9534330";
  EXPECT_EQ(expected, sol.largestNumber(nums));

  nums = {0, 0};
  expected = "0";
  EXPECT_EQ(expected, sol.largestNumber(nums));

  nums = {0};
  expected = "0";
  EXPECT_EQ(expected, sol.largestNumber(nums));

  nums = {0, 0, 0};
  expected = "0";
  EXPECT_EQ(expected, sol.largestNumber(nums));

  exit(EXIT_SUCCESS);
}
