#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> stack;
    stack.reserve(k);
    for (size_t i = 0; i < nums.size(); ++i) {
      while (!stack.empty() &&
             stack[stack.size()-1] > nums[i] &&
             stack.size() - 1 + nums.size() - i >= k) {
        stack.pop_back();
      }
      if (stack.size() < k) {
        stack.push_back(nums[i]);
      }
    }
    return stack;
  }
};

int main() {
  Solution sol;
  vector<int> nums, expected;
  int k;

  nums = {3, 5, 2, 6}, k = 2, expected = {2, 6};
  EXPECT_EQ(expected, sol.mostCompetitive(nums, k));

  nums = {2, 4, 3, 3, 5, 4, 9, 6}, k = 4, expected = {2, 3, 3, 4};
  EXPECT_EQ(expected, sol.mostCompetitive(nums, k));

  exit(EXIT_SUCCESS);
}
