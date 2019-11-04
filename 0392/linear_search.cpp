#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    size_t i = 0;
    bool ret = true;
    for (auto& c : t) {
      if (c == s[i]) {
        i++;
      }
      if (i == s.size()) {
        break;
      }
    }
    if (i < s.size()) return false;
    return ret;
  }
};


int main() {
  Solution sol;
  string s;
  string t;

  s = "abc";
  t = "ahbgdc";
  assert(sol.isSubsequence(s, t));

  s = "axc";
  t = "ahbgdc";
  assert(!sol.isSubsequence(s, t));

  s = "aec";
  t = "abcde";
  assert(!sol.isSubsequence(s, t));

  s = "";
  t = "";
  assert(sol.isSubsequence(s, t));
}
