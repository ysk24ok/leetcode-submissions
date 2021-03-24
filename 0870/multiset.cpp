#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    multiset<int> s(A.begin(), A.end());
    for (size_t i = 0; i < B.size(); ++i) {
      auto p = *s.rbegin() <= B[i] ? s.begin() : s.upper_bound(B[i]);
      A[i] = *p;
      s.erase(p);
    }
    return A;
  }
};

int main() {
  Solution sol;
  vector<int> A, B, expected;

  A = {2, 7, 11, 15}, B = {1, 10, 4, 11}, expected = {2, 11, 7, 15};
  EXPECT_EQ(expected, sol.advantageCount(A, B));

  A = {12, 24, 8, 32}, B = {13, 25, 32, 11}, expected = {24, 32, 8, 12};
  EXPECT_EQ(expected, sol.advantageCount(A, B));

  A = {2, 0, 4, 1, 2}, B = {1, 3, 0, 0, 2}, expected = {2, 4, 1, 2, 0};
  EXPECT_EQ(expected, sol.advantageCount(A, B));

  exit(EXIT_SUCCESS);
}
