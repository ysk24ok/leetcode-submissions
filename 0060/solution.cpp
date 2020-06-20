#include <cassert>
#include <cstdlib>
#include <string>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  string getPermutation(int n, int k) {
    if (n == 1) { return "1"; }
    k -= 1;   // make k zero-based
    vector<int> candidates(n);
    for (int i = 1; i <= n; ++i) { candidates[i-1] = i; }
    string ret;
    while (n > 2) {
      int divisor = factorial(n-1);
      int quotient = k / divisor;
      ret += to_string(candidates[quotient]);
      candidates.erase(candidates.begin()+quotient);
      k %= divisor;
      --n;
    }
    assert(candidates.size() == 2);
    assert(k == 0 || k == 1);
    if (k == 0) {
      ret += to_string(candidates[0]);
      ret += to_string(candidates[1]);
    } else {
      ret += to_string(candidates[1]);
      ret += to_string(candidates[0]);
    }
    return ret;
  }

  int factorial(int n) {
    int ret = 1;
    for (int i = n; i > 0; --i) {
      ret *= i;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  int n, k;
  string expected;

  n = 3, k = 1;
  expected = "123";
  EXPECT_EQ(expected, sol.getPermutation(n, k));

  n = 3, k = 2;
  expected = "132";
  EXPECT_EQ(expected, sol.getPermutation(n, k));

  n = 3, k = 3;
  expected = "213";
  EXPECT_EQ(expected, sol.getPermutation(n, k));

  n = 3, k = 4;
  expected = "231";
  EXPECT_EQ(expected, sol.getPermutation(n, k));

  n = 3, k = 5;
  expected = "312";
  EXPECT_EQ(expected, sol.getPermutation(n, k));

  n = 3, k = 6;
  expected = "321";
  EXPECT_EQ(expected, sol.getPermutation(n, k));

  n = 4, k = 9;
  expected = "2314";
  EXPECT_EQ(expected, sol.getPermutation(n, k));

  n = 2, k = 1;
  expected = "12";
  EXPECT_EQ(expected, sol.getPermutation(n, k));

  n = 1, k = 1;
  expected = "1";
  EXPECT_EQ(expected, sol.getPermutation(n, k));

  exit(EXIT_SUCCESS);
}
