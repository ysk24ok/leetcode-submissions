#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    int ret = 0;
    int m = A.size(), n = A[0].size();
    for (int i = - (m - 1); i < m; ++i) {
      for (int j = - (n - 1); j < n; ++j) {
        ret = max(ret, count(A, B, i, j));
      }
    }
    return ret;
  }

  int count(const vector<vector<int>>& A, const vector<vector<int>>& B, int ia, int ja) {
    int m = B.size(), n = B[0].size();
    int ret = 0;
    for (int ib = 0; ib < m; ++ib) {
      if (ia + ib < 0 || m <= ia + ib) { continue; }
      for (int jb = 0; jb < n; ++jb) {
        if (ja + jb < 0 || n <= ja + jb) { continue; }
        if (A[ia+ib][ja+jb] == 1 && B[ib][jb] == 1) {
          ret++;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> A, B;
  int expected;

  A = {
    {1,1,0},
    {0,1,0},
    {0,1,0}
  };
  B = {
    {0,0,0},
    {0,1,1},
    {0,0,1}
  };
  expected = 3;
  EXPECT_EQ(expected, sol.largestOverlap(A, B));

  exit(EXIT_SUCCESS);
}
