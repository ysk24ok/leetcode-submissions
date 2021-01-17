#include <gtest/gtest.h>

#include <cstdlib>

using namespace std;

class Solution {
 public:
  int countVowelStrings(int n) {
    return dfs(n, 0, 0);
  }

  // 'a': 0, 'e': 1, 'i': 2, 'o': 3, 'u': 4
  int dfs(int n, int level, int prev_vowel) {
    if (level == n) {
      return 1;
    }
    int count = 0;
    for (int vowel = prev_vowel; vowel < 5; ++vowel) {
      count += dfs(n, level + 1, vowel);
    }
    return count;
  }
};

int main() {
  Solution sol;
  int n, expected;

  n = 1, expected = 5;
  EXPECT_EQ(expected, sol.countVowelStrings(n));

  n = 2, expected = 15;
  EXPECT_EQ(expected, sol.countVowelStrings(n));

  n = 33, expected = 66045;
  EXPECT_EQ(expected, sol.countVowelStrings(n));

  exit(EXIT_SUCCESS);
}
