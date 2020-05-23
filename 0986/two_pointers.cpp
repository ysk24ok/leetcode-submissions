#include <algorithm>
#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    size_t a_idx = 0, b_idx = 0;
    vector<vector<int>> ret;
    while (a_idx < A.size() && b_idx < B.size()) {
      int start_idx = max(A[a_idx][0], B[b_idx][0]);
      int end_idx = min(A[a_idx][1], B[b_idx][1]);
      if (start_idx <= end_idx) {
        ret.push_back({start_idx, end_idx});
      }
      if (A[a_idx][1] < B[b_idx][1]) {
        a_idx++;
      } else {
        b_idx++;
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
