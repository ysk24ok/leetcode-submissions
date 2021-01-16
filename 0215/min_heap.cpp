#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq(
      nums.begin(), nums.end());
    while (pq.size() > k) {
      pq.pop();
    }
    return pq.top();
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int k, expected;

  nums = {3, 2, 1, 5, 6, 4}, k = 2, expected = 5;
  EXPECT_EQ(expected, sol.findKthLargest(nums, k));

  nums = {3, 2, 3, 1, 2, 4, 5, 5, 6}, k = 4, expected = 4;
  EXPECT_EQ(expected, sol.findKthLargest(nums, k));

  exit(EXIT_SUCCESS);
}
