#include <algorithm>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

// time complexity: O(2mn)
//  Each entry in the matrix may be visited twice.
//  (e.x. the matrix whose entries are all '1')
// space complexity: O(mn + m) when m > n
//  The memo matrix requires O(mn) and recursion occurs O(m) times
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    const size_t m = matrix.size();
    if (m == 0) { return 0; }
    const size_t n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, 0));
    int ret = 0;
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        ret = max(ret, dfs(matrix, memo, i, j));
      }
    }
    return ret * ret;
  }

  int dfs(const vector<vector<char>>& matrix, vector<vector<int>>& memo, size_t i, size_t j) {
    if (i >= matrix.size() || j >= matrix[0].size()) { return 0; }
    if (matrix[i][j] == '0') { return 0; }
    if (memo[i][j] > 0) { return memo[i][j]; }
    int ret1 = dfs(matrix, memo, i+1, j);
    int ret2 = dfs(matrix, memo, i, j+1);
    int ret3 = dfs(matrix, memo, i+1, j+1);
    memo[i][j] = min({ret1, ret2, ret3}) + 1;
    return memo[i][j];
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
}
