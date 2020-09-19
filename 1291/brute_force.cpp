#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ret;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    bool has_ended = false;
    int end = nums.size();
    while (!has_ended) {
      for (int i = 0; i < end; ++i) {
        int& num = nums[i];
        int digit = num % 10;
        if (digit == 9) {
          end -= 1;
          continue;
        }
        num *= 10;
        num += (digit + 1);
        if (num < low) {
          continue;
        }
        if (num > high) {
          has_ended = true;
          break;
        }
        ret.push_back(num);
      }
      if (end == 0) {
        has_ended = true;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int low, high;
  vector<int> expected;

  low = 100, high = 300;
  expected = {123, 234};
  EXPECT_EQ(expected, sol.sequentialDigits(low, high));

  low = 1000, high = 13000;
  expected = {1234, 2345, 3456, 4567, 5678, 6789, 12345};
  EXPECT_EQ(expected, sol.sequentialDigits(low, high));

  low = 10, high = 1000000000;
  sol.sequentialDigits(low, high);

  exit(EXIT_SUCCESS);
}
