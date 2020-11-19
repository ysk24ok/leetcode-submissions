#include <gtest/gtest.h>

#include <cstdlib>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    stack<pair<int, string>> st;
    string curr_str;
    string curr_num;
    for (const char& c : s) {
      if (c == '[') {
        st.push({stoi(curr_num), curr_str});
        curr_str = "";
        curr_num = "";
      } else if (c == ']') {
        pair<int, string> p = st.top();
        st.pop();
        string next_str;
        for (int j = 0; j < p.first; ++j) {
          next_str += curr_str;
        }
        curr_str = p.second + next_str;
      } else if (isdigit(c) != 0) {
        curr_num += c;
      } else {
        curr_str += c;
      }
    }
    return curr_str;
  }
};

int main() {
  Solution sol;
  string s, expected;

  s = "3[a]2[bc]", expected = "aaabcbc";
  EXPECT_EQ(expected, sol.decodeString(s));

  s = "3[a2[c]]", expected = "accaccacc";
  EXPECT_EQ(expected, sol.decodeString(s));

  s = "2[abc]3[cd]ef", expected = "abcabccdcdcdef";
  EXPECT_EQ(expected, sol.decodeString(s));

  s = "abc3[cd]xyz", expected = "abccdcdcdxyz";
  EXPECT_EQ(expected, sol.decodeString(s));

  exit(EXIT_SUCCESS);
}
