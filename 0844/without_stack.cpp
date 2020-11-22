#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  bool backspaceCompare(string& S, string& T) {
    return create(S) == create(T);
  }

  string create(const string& str) {
    string ret;
    int backspace_count = 0;
    for (int i = str.size() - 1; i >= 0; --i) {
      if (str[i] == '#') {
        backspace_count++;
      } else {
        if (backspace_count > 0) {
          backspace_count--;
        } else {
          ret += str[i];
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string S, T;

  S = "ab#c", T = "ad#c";
  EXPECT_TRUE(sol.backspaceCompare(S, T));

  S = "ab##", T = "c#d#";
  EXPECT_TRUE(sol.backspaceCompare(S, T));

  S = "a##c", T = "#a#c";
  EXPECT_TRUE(sol.backspaceCompare(S, T));

  S = "a#c", T = "b";
  EXPECT_FALSE(sol.backspaceCompare(S, T));

  S = "cc######", T = "###";
  EXPECT_TRUE(sol.backspaceCompare(S, T));

  exit(EXIT_SUCCESS);
}
