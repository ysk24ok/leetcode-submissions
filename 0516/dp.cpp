#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void print_matrix(const vector<vector<int>>& matrix) {
  for (auto& vec : matrix) {
    for (auto& v : vec) {
      cout << v << " ";
    }
    cout << endl;
  }
  cout << endl;
}

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    size_t n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    cout << endl;
    for (int i = n - 1; i >= 0; i--) {
      dp[i][i] = 1;
      for (int j = i+1; j < n; j++) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i+1][j-1] + 2;
        } else {
          dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
      }
    }
    //print_matrix(dp);
    return dp[0][n-1];
  }
};

int main() {
  Solution sol;
  string s;

  s = "bbbab";
  assert(sol.longestPalindromeSubseq(s) == 4);
  s = "cbbd";
  assert(sol.longestPalindromeSubseq(s) == 2);
  s = "dbcacdb";
  assert(sol.longestPalindromeSubseq(s) == 5);
}
