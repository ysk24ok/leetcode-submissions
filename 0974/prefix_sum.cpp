#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int subarraysDivByK(vector<int>& A, int K) {
    unordered_map<int, int> count;
    count[0] = 1;
    int prefix_sum = 0;
    int ret = 0;
    for (const auto& a : A) {
      prefix_sum += a;
      while (prefix_sum < 0) { prefix_sum += K; }
      prefix_sum %= K;
      count[prefix_sum]++;
      ret += count[prefix_sum] - 1;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> A;
  int K, expected;

  A = {4,5,0};
  K = 5, expected = 3;
  //EXPECT_EQ(expected, sol.subarraysDivByK(A, K));

  A = {4,5,0,-2,-3,1};
  K = 5, expected = 7;
  EXPECT_EQ(expected, sol.subarraysDivByK(A, K));
}
