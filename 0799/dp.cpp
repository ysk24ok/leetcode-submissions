#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    std::vector<std::vector<double>> table;
    table.push_back({0.0});
    table[0][0] += poured;
    for (int row = 1; row <= query_row; row++) {
      std::vector<double> vec(row+1, 0.0);
      table.push_back(vec);
      for (int glass = 0; glass < row; glass++) {
        if (table[row-1][glass] <= 1.0) continue;
        double w = (table[row-1][glass] - 1.0) / 2.0;
        table[row][glass] += w;
        table[row][glass+1] += w;
      }
    }
    double ret = table[query_row][query_glass];
    return (ret >= 1.0) ? 1.0 : ret;
  }
};

int main() {
  Solution sol;
  double got;

  got = sol.champagneTower(0, 0, 0);
  assert(got == 0.0);

  got = sol.champagneTower(1, 0, 0);
  assert(got == 1.0);

  got = sol.champagneTower(1, 1, 1);
  assert(got == 0.0);

  got = sol.champagneTower(2, 1, 1);
  assert(got == 0.5);

  got = sol.champagneTower(4, 1, 1);
  assert(got == 1.0);

  got = sol.champagneTower(4, 2, 1);
  assert(got == 0.5);

  got = sol.champagneTower(4, 2, 2);
  assert(got == 0.25);
}
