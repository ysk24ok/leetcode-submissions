#include <gtest/gtest.h>

#include <cctype>
#include <queue>
#include <string>

using namespace std;

class Solution {
 public:
  string reformat(string s) {
    queue<char> number_q;
    queue<char> alpha_q;
    for (const auto& c : s) {
      // number
      if (isdigit(static_cast<int>(c)) != 0) {
        number_q.push(c);
      } else {
        alpha_q.push(c);
      }
    }
    string ret;
    int diff = number_q.size() - alpha_q.size();
    if (diff == 1 || diff == 0) { push(ret, number_q, alpha_q); }
    else if (diff == -1) { push(ret, alpha_q, number_q); }
    else { return ret; }
    return ret;
  }

  void push(string& ret, queue<char>& q1, queue<char>& q2) {
    assert(q1.size() >= q2.size());
    while (!q1.empty() || !q2.empty()) {
      char c1 = q1.front();
      q1.pop();
      ret += c1;
      if (q2.empty()) continue;
      char c2 = q2.front();
      q2.pop();
      ret += c2;
    }
  }
};

int main() {
  Solution sol;
  string s, expected;

  s = "a0b1c2";
  expected = "0a1b2c";
  EXPECT_EQ(expected, sol.reformat(s));

  s = "leetcode";
  expected = "";
  EXPECT_EQ(expected, sol.reformat(s));

  s = "1229857369";
  expected = "";
  EXPECT_EQ(expected, sol.reformat(s));

  s = "covid2019";
  expected = "c2o0v1i9d";
  EXPECT_EQ(expected, sol.reformat(s));

  s = "ab123";
  expected = "1a2b3";
  EXPECT_EQ(expected, sol.reformat(s));
}
