#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int calculate(string s) {
    vector<pair<int, char>> stack;
    size_t i = 0;
    while (i < s.size()) {
      while (s[i] == ' ') { i++; }
      int number = 0;
      while (0 <= s[i] - '0' && s[i] - '0' < 10) {
        number *= 10;
        number += s[i] - '0';
        i++;
      }
      while (i < s.size() && s[i] == ' ') { i++; }
      char op = ' ';
      if (i < s.size()) {
        op = s[i++];
      }
      if (stack.size() == 0) {
        stack.push_back({number, op});
        continue;
      }
      pair<int, char> elem = stack.back();
      if (elem.second == '*') {
        stack.pop_back();
        number *= elem.first;
      } else if (elem.second == '/') {
        stack.pop_back();
        number = elem.first / number;
      }
      stack.push_back({number, op});
    }
    int ret = stack[0].first;
    char prev_op = stack[0].second;
    for (size_t i = 1; i < stack.size(); ++i) {
      char op = stack[i].second;
      if (prev_op == '+') {
        ret += stack[i].first;
      } else if (prev_op == '-') {
        ret -= stack[i].first;
      }
      prev_op = op;
    }
    return ret;
  }
};


int main() {
  Solution sol;
  string s;
  int expected;

  s = "3+2*2";
  expected = 7;
  EXPECT_EQ(expected, sol.calculate(s));

  s = " 3/2 ";
  expected = 1;
  EXPECT_EQ(expected, sol.calculate(s));

  s = " 3+5 / 2 ";
  expected = 5;
  EXPECT_EQ(expected, sol.calculate(s));

  s = "42";
  expected = 42;
  EXPECT_EQ(expected, sol.calculate(s));

  s = "1-1+1";
  expected = 1;
  EXPECT_EQ(expected, sol.calculate(s));

  exit(EXIT_SUCCESS);
}
