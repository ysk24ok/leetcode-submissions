#include <cassert>
#include <iostream>
#include <string>

using namespace std;

// XXX: TLE
// time complexity: O(2^(m+n)) (worst case where recursion occurs every time,
//                              such as s1="aaab", s2="aaac" and s3="aaaaaacb")
//                  O(m+n) (best case where no recursion occurs,
//                          such as s1="abcd", s2="efgh" and s3="aebfcgdh")
// space complexity: O(m+n) (worst case where recursion occurs every time)
//                   O(1) (best case where no recursion occurs)
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    return backtracking(s1, s2, s3, 0, 0, 0);
  }

  bool backtracking(const string& s1, const string& s2, const string& s3,
                    int p1, int p2, int p3) {
    bool ret = true;
    for (int p = p3; p < s3.size(); p++) {
      const char& c = s3[p];
      if (c == s1[p1] && (c != s2[p2] || p2 >= s2.size())) {
        p1++;
      } else if (c == s2[p2] && (c != s1[p1] || p1 >= s1.size())) {
        p2++;
      } else if (c == s1[p1] && c == s2[p2]) {
        bool ret1 = backtracking(s1, s2, s3, p1+1, p2, p+1);
        if (ret1) break;
        bool ret2 = backtracking(s1, s2, s3, p1, p2+1, p+1);
        if (ret2) break;
        if (!ret1 && !ret2) ret = false;
      } else {
        ret = false;
        break;
      }
    }
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
