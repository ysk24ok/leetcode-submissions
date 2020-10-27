#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> curr(query_row+1), next(query_row+1);
    curr[0] = poured;
    for (int row = 0; row < query_row; ++row) {
      int num_glasses = row + 1;
      for (auto& val : next) { val = 0.0; }
      for (int glass = 0; glass < num_glasses; ++glass) {
        if (curr[glass] <= 1.0) {
          continue;
        }
        double half = (curr[glass] - 1.0) / 2;
        next[glass] += half;
        next[glass+1] += half;
      }
      curr.swap(next);
    }
    return curr[query_glass] >= 1.0 ? 1.0 : curr[query_glass];
  }
};

int main() {
  Solution sol;
  int poured, query_row, query_glass;
  double expected;

  {
    poured = 0, query_row = 0, query_glass = 0;
    expected = 0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));
  }

  {
    poured = 1, query_row = 0, query_glass = 0;
    expected = 1.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 1, query_row = 1, query_glass = 0;
    expected = 0.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 1, query_row = 1, query_glass = 1;
    expected = 0.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));
  }

  {
    poured = 2, query_row = 0, query_glass = 0;
    expected = 1.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 2, query_row = 1, query_glass = 0;
    expected = 0.5;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 2, query_row = 1, query_glass = 1;
    expected = 0.5;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));
  }

  {
    poured = 3, query_row = 0, query_glass = 0;
    expected = 1.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 3, query_row = 1, query_glass = 0;
    expected = 1.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 3, query_row = 1, query_glass = 1;
    expected = 1.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));
  }

  {
    poured = 4, query_row = 0, query_glass = 0;
    expected = 1.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 4, query_row = 1, query_glass = 0;
    expected = 1.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 4, query_row = 1, query_glass = 1;
    expected = 1.0;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 4, query_row = 2, query_glass = 0;
    expected = 0.25;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 4, query_row = 2, query_glass = 1;
    expected = 0.5;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

    poured = 4, query_row = 2, query_glass = 2;
    expected = 0.25;
    EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));
  }

  poured = 100000009, query_row = 33, query_glass = 17;
  expected = 1.0;
  EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

  poured = 25, query_row = 6, query_glass = 1;
  expected = 0.1875;
  EXPECT_EQ(expected, sol.champagneTower(poured, query_row, query_glass));

  exit(EXIT_SUCCESS);
}
