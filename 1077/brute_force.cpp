#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int ret = numeric_limits<int>::max();
    int ret1 = check(A, B, A[0]);
    if (ret1 != -1) { ret = min(ret, ret1); }
    int ret2 = check(A, B, B[0]);
    if (ret2 != -1) { ret = min(ret, ret2); }
    int ret3 = check(B, A, A[0]);
    if (ret3 != -1) { ret = min(ret, ret3); }
    int ret4 = check(B, A, B[0]);
    if (ret4 != -1) { ret = min(ret, ret4); }
    return ret != numeric_limits<int>::max() ? ret : -1;
  }

  int check(vector<int>& target, vector<int>& other, int val) {
    vector<int> swapped;
    for (size_t i = 0; i < target.size(); ++i) {
      if (target[i] == val) { continue; }
      swap(target, other, i);
      swapped.push_back(i);
      if (target[i] != val) {
        for (const int& idx : swapped) {
          swap(target, other, idx);
        }
        return -1;
      }
    }
    for (const int& idx : swapped) {
      swap(target, other, idx);
    }
    return swapped.size();
  }

  void swap(vector<int>& left, vector<int>& right, size_t idx) {
    int tmp = left[idx];
    left[idx] = right[idx];
    right[idx] = tmp;
  }
};

int main() {
  Solution sol;
  vector<int> A, B;
  int expected;

  A = {2,1,2,4,2,2}, B = {5,2,6,2,3,2};
  expected = 2;
  EXPECT_EQ(expected, sol.minDominoRotations(A, B));

  A = {3,5,1,2,3}, B = {3,6,3,3,4};
  expected = -1;
  EXPECT_EQ(expected, sol.minDominoRotations(A, B));

  A = {1,1,1,1,1,1,1,1}, B = {1,1,1,1,1,1,1,1};
  expected = 0;
  EXPECT_EQ(expected, sol.minDominoRotations(A, B));

  A = {1,2,1,1,1,2,2,2}, B = {2,1,2,2,2,2,2,2};
  expected = 1;
  EXPECT_EQ(expected, sol.minDominoRotations(A, B));

  exit(EXIT_SUCCESS);
}
