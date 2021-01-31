#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    auto greater = [](const pair<int, int>& l, const pair<int, int>& r) {
      return l.first > r.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> min_heap(greater);
    int max_num = 0;
    for (const int& orig_num : nums) {
      int num = orig_num;
      while (num % 2 == 0) {
        num /= 2;
      }
      min_heap.push({num, orig_num});
      max_num = max(num, max_num);
    }
    int diff = numeric_limits<int>::max();
    while (min_heap.size() == nums.size()) {
      int curr_num = min_heap.top().first;
      int orig_num = min_heap.top().second;
      min_heap.pop();
      diff = min(max_num - curr_num, diff);
      if (curr_num % 2 == 1 || curr_num < orig_num) {
        int new_num = curr_num * 2;
        max_num = max(new_num, max_num);
        min_heap.push({new_num, orig_num});
      }
    }
    return diff;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  nums = {1, 2, 3, 4}, expected = 1;
  EXPECT_EQ(expected, sol.minimumDeviation(nums));

  nums = {4, 1, 5, 20, 3}, expected = 3;
  EXPECT_EQ(expected, sol.minimumDeviation(nums));

  nums = {2, 10, 8}, expected = 3;
  EXPECT_EQ(expected, sol.minimumDeviation(nums));

  exit(EXIT_SUCCESS);
}
