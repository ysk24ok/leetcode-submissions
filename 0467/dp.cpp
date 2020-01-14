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

class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    if (p.size() <= 1) return p.size();
    vector<int> dp(26, 0);
    int start = 0;
    int prev = 0;
    for (int i = 0; i < p.size(); i++) {
      if (!isContiguous(p[prev], p[i])) {
        count(p, start, prev, dp);
        start = i;
      }
      prev = i;
    }
    count(p, start, prev, dp);
    return accumulate(dp.begin(), dp.end(), 0);
  }

  void count(const string& str, int i, int j, vector<int>& dp) {
    if (i > j) return;
    int idx = int(str[j]) - int('a');
    dp[idx] = max(dp[idx], j - i + 1);
    count(str, i, j-1, dp);
  }

  bool isContiguous(const char& c1, const char& c2) {
    if (c1 == 'z' && c2 == 'a') return true;
    return (int(c2) - int(c1)) == 1;
  }
};

int main() {
  Solution sol;
  string p;

  p = "s";
  assert(sol.findSubstringInWraproundString(p) == 1);

  p = "ab";
  assert(sol.findSubstringInWraproundString(p) == 3);

  p = "cac";
  assert(sol.findSubstringInWraproundString(p) == 2);

  p = "zab";
  assert(sol.findSubstringInWraproundString(p) == 6);

  // a
  // ab,b
  // abc,bc,c
  // abcd,bcd,cd,d
  p = "abcdab";
  assert(sol.findSubstringInWraproundString(p) == 10);

  p = "aceg";
  assert(sol.findSubstringInWraproundString(p) == 4);

  p = "";
  assert(sol.findSubstringInWraproundString(p) == 0);
}
