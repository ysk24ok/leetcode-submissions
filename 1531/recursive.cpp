#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

// idx x character x count x k
int memo[101][26][101][101];

// XXX: TLE
class Solution {
 public:
  int getLengthOfOptimalCompression(string s, int k) {
    const size_t m = s.size();
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j < 26; j++) {
        for (int k = 0; k <= m; k++) {
          for (int l = 0; l <= m; l++) {
            memo[i][j][k][l] = -1;
          }
        }
      }
    }
    return recursive(s, 0, '-', 1, k);
  }

  int recursive(const string& s, size_t idx, char last_char, int count, int k) {
    if (idx == s.size()) {
      return get_length(last_char, count);
    }
    if (last_char != '-' && memo[idx][last_char-'a'][count][k] != -1) {
      return memo[idx][last_char-'a'][count][k];
    }
    int ret = numeric_limits<int>::max();
    if (k > 0) {
      ret = min(ret, recursive(s, idx+1, last_char, count, k-1));
    }
    char curr_char = s[idx];
    if (curr_char == last_char) {
      ret = min(ret, recursive(s, idx+1, curr_char, count+1, k));
    } else {
      int length = get_length(last_char, count);
      ret = min(ret, recursive(s, idx+1, curr_char, 1, k) + length);
    }
    if (last_char != '-') {
      memo[idx][last_char-'a'][count][k] = ret;
    }
    return ret;
  }

  int get_length(char last_char, int count) {
    if (last_char == '-') {
      return 0;
    }
    if (count == 1) {
      return 1;
    } else if (count < 10) {
      return 2;
    } else if (count < 100) {
      return 3;
    } else {
      return 4;
    }
  }
};

int main() {
  Solution sol;
  string s;
  int k, expected;

  s = "aaabcccd", k = 2, expected = 4;
  EXPECT_EQ(expected, sol.getLengthOfOptimalCompression(s, k));

  s = "aabbaa", k = 2, expected = 2;
  EXPECT_EQ(expected, sol.getLengthOfOptimalCompression(s, k));

  s = "aaaaaaaaaaa", k = 0, expected = 3;
  EXPECT_EQ(expected, sol.getLengthOfOptimalCompression(s, k));

  exit(EXIT_SUCCESS);
}
