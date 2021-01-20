#include <gtest/gtest.h>

#include <cstdlib>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> st;
    for (const char& c : s) {
      if (c == '(' || c == '[' || c == '{') {
        st.push(c);
      } else {
        if (st.empty()) { return false; }
        if ((st.top() == '(' && c == ')') ||
            (st.top() == '[' && c == ']') ||
            (st.top() == '{' && c == '}')) {
          st.pop();
        } else {
          return false;
        }
      }
    }
    return st.empty();
  }
};

int main() {
  Solution sol;
  string s;
  bool expected;

  s = "()", expected = true;
  EXPECT_EQ(expected, sol.isValid(s));

  s = "()[]{}", expected = true;
  EXPECT_EQ(expected, sol.isValid(s));

  s = "(]", expected = false;
  EXPECT_EQ(expected, sol.isValid(s));

  s = "([)]", expected = false;
  EXPECT_EQ(expected, sol.isValid(s));

  s = "{[]}", expected = true;
  EXPECT_EQ(expected, sol.isValid(s));

  s = "[", expected = false;
  EXPECT_EQ(expected, sol.isValid(s));

  exit(EXIT_SUCCESS);
}
