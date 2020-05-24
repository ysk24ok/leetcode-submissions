#include <algorithm>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    unordered_map<int, vector<size_t>> map;
    const size_t m = A.size();
    vector<int> unique_val;
    for (size_t i = 0; i < m; ++i) {
      const int& num = A[i];
      if (map.find(num) == map.end()) {
        unique_val.push_back(num);
      }
      map[num].push_back(i);
    }
    // A: [9,8,1,0,1,9,4,0,4,1];
    // map: {0: [3,7], 1: [2,4,9], 4: [6,8], 8: [1], 9: [2,5]}
    // unique_val: [0,1,4,8,9]
    std::sort(unique_val.begin(), unique_val.end());
    int ret = 0;
    size_t minimum_idx = m;
    for (const int& val : unique_val) {
      for (const size_t& idx : map[val]) {
        ret = max(ret, static_cast<int>(idx) - static_cast<int>(minimum_idx));
        minimum_idx = min(minimum_idx, idx);
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> A;
  int got, expected;

  A = {6,0,8,2,1,5};
  got = sol.maxWidthRamp(A);
  expected = 4;
  EXPECT_EQ(expected, got);

  A = {};
  got = sol.maxWidthRamp(A);
  expected = 0;
  EXPECT_EQ(expected, got);

  A = {1};
  got = sol.maxWidthRamp(A);
  expected = 0;
  EXPECT_EQ(expected, got);

  A = {9,8,1,0,1,9,4,0,4,1};
  got = sol.maxWidthRamp(A);
  expected = 7;
  EXPECT_EQ(expected, got);

  A = {7,8,9,1,2,3,4,5,6};
  got = sol.maxWidthRamp(A);
  expected = 5;
  EXPECT_EQ(expected, got);

  A = {1,2,3,0};
  got = sol.maxWidthRamp(A);
  expected = 2;
  EXPECT_EQ(expected, got);
}
