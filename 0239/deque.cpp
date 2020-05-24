#include <cassert>
#include <cstdlib>
#include <deque>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // The deque contains indices within range k
    deque<int> q;
    vector<int> ret;
    for (int i = 0; i < nums.size(); ++i) {
      // Remove an index out of range k from the tail
      while (!q.empty() && q.back() < i - k + 1) {
        q.pop_back();
      }
      // Remove smaller numbers than nums[i] in k range as they are useless
      // This operation ensures that the index of the maximum number exists at the tail
      while (!q.empty() && nums[q.front()] < nums[i]) {
        q.pop_front();
      }
      // push this index to the front
      q.push_front(i);
      if (i >= k - 1) { ret.push_back(nums[q.back()]); }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums, got, expected;
  int k;

  nums = {1,3,-1,-3,5,3,6,7};
  k = 3;
  expected = {3,3,5,5,6,7};
  got = sol.maxSlidingWindow(nums, k);
  assert(expected.size() == got.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(expected[i], got[i]);
  }

  exit(EXIT_SUCCESS);
}
