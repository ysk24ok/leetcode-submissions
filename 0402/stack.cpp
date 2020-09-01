#include <gtest/gtest.h>

#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    stack<char> st;
    size_t i = 0;
    while (i < num.size()) {
      while (!st.empty() && k > 0 && (static_cast<int>(st.top()) > static_cast<int>(num[i]))) {
        st.pop();
        --k;
      }
      st.push(num[i++]);
    }
    while (k > 0 && !st.empty()) {
      st.pop();
      --k;
    }
    string ret;
    while (!st.empty()) {
      char c = st.top();
      st.pop();
      ret.insert(ret.begin(), c);
    }
    while (ret[0] == '0') { ret.erase(0, 1); }
    if (ret.size() == 0) { return "0"; }
    return ret;
  }
};

int main() {
  Solution sol;
  string num, expected;
  int k;

  num = "1432219";
  k = 3;
  expected = "1219";
  EXPECT_EQ(expected, sol.removeKdigits(num, k));

  num = "10200";
  k = 1;
  expected = "200";
  EXPECT_EQ(expected, sol.removeKdigits(num, k));

  num = "10";
  k = 2;
  expected = "0";
  EXPECT_EQ(expected, sol.removeKdigits(num, k));

  num = "9876";
  k = 2;
  expected = "76";
  EXPECT_EQ(expected, sol.removeKdigits(num, k));

  num = "1234";
  k = 2;
  expected = "12";
  EXPECT_EQ(expected, sol.removeKdigits(num, k));

  num = "1234321";
  k = 2;
  expected = "12321";
  EXPECT_EQ(expected, sol.removeKdigits(num, k));

  num = "9";
  k = 1;
  expected = "0";
  EXPECT_EQ(expected, sol.removeKdigits(num, k));

  num = "1173";
  k = 2;
  expected = "11";
  EXPECT_EQ(expected, sol.removeKdigits(num, k));

  num = "1234567890";
  k = 9;
  expected = "0";
  EXPECT_EQ(expected, sol.removeKdigits(num, k));
}
