#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    if (nums.size() == 0) { return ret; }
    int interval_start = nums[0];
    int interval_end = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      if (nums[i-1] + 1 != nums[i]) {
        add(ret, interval_start, interval_end);
        interval_start = nums[i];
      }
      interval_end = nums[i];
    }
    add(ret, interval_start, interval_end);
    return ret;
  }

  void add(vector<string>& ret, int interval_start, int interval_end) {
    if (interval_start == interval_end) {
      ret.push_back(to_string(interval_start));
    } else {
      ret.push_back(to_string(interval_start) + "->" + to_string(interval_end));
    }
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  vector<string> expected;

  nums = {0, 1, 2, 4, 5, 7};
  expected = {"0->2", "4->5", "7"};
  EXPECT_EQ(expected, sol.summaryRanges(nums));

  nums = {0, 2, 3, 4, 6, 8, 9};
  expected = {"0", "2->4", "6", "8->9"};
  EXPECT_EQ(expected, sol.summaryRanges(nums));

  nums = {};
  expected = {};
  EXPECT_EQ(expected, sol.summaryRanges(nums));

  nums = {-1};
  expected = {"-1"};
  EXPECT_EQ(expected, sol.summaryRanges(nums));

  exit(EXIT_SUCCESS);
}
