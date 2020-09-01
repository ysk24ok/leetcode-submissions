#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void reverseString(vector<char>& s) {
    size_t left = 0, right = s.size();
    while (left < right) {
      char tmp = s[left];
      s[left] = s[right-1];
      s[right-1] = tmp;
      left++;
      right--;
    }
  }
};

void check(const vector<char>& expected, const vector<char>& got) {
  ASSERT_EQ(expected.size(), got.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    EXPECT_EQ(expected[i], got[i]);
  }
}

int main() {
  Solution sol;
  vector<char> s, expected;

  s = {'h','e','l','l','o'};
  expected = {'o','l','l','e','h'};
  sol.reverseString(s);
  check(expected, s);

  exit(EXIT_SUCCESS);
}
