#include <gtest/gtest.h>

#include <cmath>
#include <vector>

using namespace std;

// time complexity: O(n * 2^n)
// space complexity: O(2^n)
class Solution {
 public:
  vector<int> grayCode(int n) {
    size_t num = pow(2, n);
    vector<int> ret(num);
    vector<bool> appeared(num, false);
    ret[0] = 0;
    appeared[0] = true;
    for (size_t i = 1; i < num; ++i) {
      int prev = ret[i - 1];
      for (size_t j = 0; j < n; ++j) {
        int value;
        int digit = pow(2, j);
        if (prev & digit) {  // the bit is 1
          value = prev - digit;
        } else {
          value = prev + digit;
        }
        if (appeared[value]) {
         continue;
        }
        ret[i] = value;
        appeared[value] = true;
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int n;
  vector<int> expected;

  n = 0;
  expected = {0};
  EXPECT_EQ(expected, sol.grayCode(n));

  n = 1;
  expected = {0, 1};
  EXPECT_EQ(expected, sol.grayCode(n));

  n = 2;
  // 00 01 11 10
  expected = {0,1,3,2};
  EXPECT_EQ(expected, sol.grayCode(n));

  n = 3;
  // 000 001 011 010 110 111 101 100
  expected = {0,1,3,2,6,7,5,4};
  EXPECT_EQ(expected, sol.grayCode(n));

  n = 4;
  // 0000 0001 0011 0010 0110 0111 0101 0100
  // 1100 1101 1111 1110 1010 1011 1001 1000
  expected = {0,1,3,2,6,7,5,4,12,13,15,14,10,11,9,8};
  EXPECT_EQ(expected, sol.grayCode(n));
}
