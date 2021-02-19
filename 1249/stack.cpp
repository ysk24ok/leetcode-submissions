#include <gtest/gtest.h>

#include <cstdlib>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    stack<size_t> st;
    string ret;
    for (const char& c : s) {
      if (c == '(') {
        ret += c;
        st.push(ret.size()-1);
      } else if (c == ')') {
        if (!st.empty()) {
          st.pop();
          ret += c;
        }
      } else {
        ret += c;
      }
    }
    while (!st.empty()) {
      ret.erase(st.top(), 1);
      st.pop();
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s, expected;

  s = "lee(t(c)o)de)", expected = "lee(t(c)o)de";
  EXPECT_EQ(expected, sol.minRemoveToMakeValid(s));

  s = "a)b(c)d", expected = "ab(c)d";
  EXPECT_EQ(expected, sol.minRemoveToMakeValid(s));

  s = "))((", expected = "";
  EXPECT_EQ(expected, sol.minRemoveToMakeValid(s));

  s = "(a(b(c)d)", expected = "a(b(c)d)";
  EXPECT_EQ(expected, sol.minRemoveToMakeValid(s));

  exit(EXIT_SUCCESS);
}
