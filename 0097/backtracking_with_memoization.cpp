#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// time complexity: O(mn) (worst case where you have to check all combinations
//                         of s1 and s2)
//                  O(m+n) (best case where no recursion occurs,
//                          such as s1="abcd", s2="efgh" and s3="aebfcgdh")
// space complexity: O(mn) (memoization needs m x n matrix)
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    vector<vector<int>> memo(s1.size()+1, vector<int>(s2.size()+1, -1));
    if (s1.size() + s2.size() != s3.size()) return false;
    int p1 = 0, p2 = 0, p3 = 0;
    return backtracking(s1, s2, s3, p1, p2, p3, memo);
  }

  bool backtracking(const string& s1, const string& s2, const string& s3,
                    int p1, int p2, int p3, vector<vector<int>>& memo) {
    bool ret = true;
    for (int p = p3; p < s3.size(); p++) {
      const char& c = s3[p];
      if (memo[p1][p2] == 1) return true;
      else if (memo[p1][p2] == 0) return false;
      if (c == s1[p1] && (c != s2[p2] || p2 >= s2.size())) {
        p1++;
      } else if (c == s2[p2] && (c != s1[p1] || p1 >= s1.size())) {
        p2++;
      } else if (c == s1[p1] && c == s2[p2]) {
        bool ret1 = backtracking(s1, s2, s3, p1+1, p2, p+1, memo);
        if (ret1) break;
        bool ret2 = backtracking(s1, s2, s3, p1, p2+1, p+1, memo);
        if (ret2) break;
        if (!ret1 && !ret2) ret = false;
      } else {
        ret = false;
        break;
      }
    }
    memo[p1][p2] = ret ? 1 : 0;
    return ret;
  }
};

int main() {
  Solution sol;
  string s1, s2, s3;

  //    0123456789
  s1 = "aabcc";
  s2 = "dbbca";
  s3 = "aadbbcbcac";
  assert(sol.isInterleave(s1, s2, s3));

  //    0123456789
  s1 = "aabcc";
  s2 = "dbbca";
  s3 = "aadbbbaccc";
  assert(!sol.isInterleave(s1, s2, s3));

  s1 = "a";
  s2 = "b";
  s3 = "a";
  assert(!sol.isInterleave(s1, s2, s3));

  s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
  s2 ="babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
  s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
  assert(!sol.isInterleave(s1, s2, s3));
}
