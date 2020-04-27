#include <algorithm>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

// time complexity: O(mn)
// time complexity: O(n)
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    const size_t m = matrix.size();
    if (m == 0) { return 0; }
    const size_t n = matrix[0].size();
    vector<int> dp_prev(n+1, 0);
    int ret = 0;
    for (size_t i = 1; i <= m; ++i) {
      vector<int> dp_curr(n+1, 0);
      for (size_t j = 1; j <= n; ++j) {
        if (matrix[i-1][j-1] == '0') { continue; }
        dp_curr[j] = min({dp_curr[j-1], dp_prev[j], dp_prev[j-1]}) + 1;
        ret = max(ret, dp_curr[j]);
      }
      dp_prev.swap(dp_curr);
    }
    return ret * ret;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> matrix;

  matrix = {
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'},
  };
  ExpectEqual(4, sol.maximalSquare(matrix));

  matrix = {
    {'0','1','1','1','0'},
    {'1','1','1','0','0'},
    {'1','1','1','1','0'},
    {'1','1','1','1','0'},
  };
  ExpectEqual(9, sol.maximalSquare(matrix));

  matrix = {
    {'0','1','1','1','0'},
    {'1','1','0','0','0'},
    {'0','1','1','0','0'},
    {'1','0','1','1','0'},
  };
  ExpectEqual(1, sol.maximalSquare(matrix));

  matrix = {};
  ExpectEqual(0, sol.maximalSquare(matrix));
}
