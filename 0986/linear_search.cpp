#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

// XXX: TLE
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    size_t a_idx = 0, b_idx = 0;
    size_t idx = 0;
    vector<vector<int>> ret;
    bool is_in_intersection = false;
    int start_idx;
    while (a_idx < A.size() && b_idx < B.size()) {
      bool in_a = false;
      if (A[a_idx][0] <= idx && idx <= A[a_idx][1]) { in_a = true; }
      bool in_b = false;
      if (B[b_idx][0] <= idx && idx <= B[b_idx][1]) { in_b = true; }
      if (in_a && in_b) {
        if (!is_in_intersection) {
          is_in_intersection = true;
          start_idx = idx;
        }
      }
      idx++;
      if (A[a_idx][1] < idx) {
        a_idx++;
        if (is_in_intersection) {
          ret.push_back({start_idx, A[a_idx-1][1]});
          is_in_intersection = false;
        }
      }
      if (B[b_idx][1] < idx) {
        b_idx++;
        if (is_in_intersection) {
          ret.push_back({start_idx, B[b_idx-1][1]});
          is_in_intersection = false;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> A, B, got, expected;

  A = {{0,2},{5,10},{13,23},{24,25}}, B = {{1,5},{8,12},{15,24},{25,26}};
  got = sol.intervalIntersection(A, B);
  expected = {{1,2},{5,5},{8,10},{15,23},{24,24},{25,25}};
  assert(got.size() == expected.size());
  for (size_t i = 0; i < got.size(); ++i) {
    EXPECT_EQ(expected[i][0], got[i][0]);
    EXPECT_EQ(expected[i][1], got[i][1]);
  }
  exit(EXIT_SUCCESS);
}
