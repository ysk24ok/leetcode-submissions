#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int, int> map;
    for (const int& a : A) {
      for (const int& b : B) {
        map[a + b]++;
      }
    }
    int ret = 0;
    for (const int& c : C) {
      for (const int& d : D) {
        if (map.find(0 - c - d) != map.end()) {
          ret += map[0 - c - d];
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> A, B, C, D;
  int expected;

  A = {1, 2}, B = {-2, -1}, C = {-1, 2}, D = {0, 2};
  expected = 2;
  EXPECT_EQ(expected, sol.fourSumCount(A, B, C, D));

  exit(EXIT_SUCCESS);
}
