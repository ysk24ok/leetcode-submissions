#include <stack>
#include <string>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool checkValidString(string s) {
    stack<size_t> ast;
    stack<size_t> par;
    for (size_t i = 0; i < s.size(); ++i) {
      const char& c = s[i];
      if (c == '(') { par.push(i); }
      else if (c == ')') {
        if (par.empty()) {
          if (ast.size() > 0 && ast.top() < i) {
            ast.pop();
          } else if (ast.size() == 0) { return false; }
        } else {
          par.pop();
        }
      } else { ast.push(i); }
    }
    if (ast.size() == 0) return par.size() == 0;
    while (!par.empty() && !ast.empty()) {
      if (par.top() < ast.top()) {
        par.pop();
        ast.pop();
      } else { break; }
    }
    return par.size() == 0;
  }
};

int main() {
  Solution sol;

  ExpectEqual(true, sol.checkValidString("()"));
  ExpectEqual(true, sol.checkValidString("(*)"));
  ExpectEqual(true, sol.checkValidString("(*))"));
  ExpectEqual(false, sol.checkValidString("((())"));
  ExpectEqual(true, sol.checkValidString("((*())"));
  ExpectEqual(false, sol.checkValidString("*("));
  ExpectEqual(true, sol.checkValidString("*((*)))"));
  // WA
  ExpectEqual(true, sol.checkValidString("(((******))"));
  // WA
  ExpectEqual(false, sol.checkValidString("(())((())()()(*)(*()(())())())()()((()())((()))(*"));
}
