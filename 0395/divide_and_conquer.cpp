#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cstdlib>
#include <string>

using namespace std;

class Solution {
 public:
  int longestSubstring(string s, int k) {
    return divideAndConquer(s, k, 0, s.size()-1);
  }

  int divideAndConquer(const string& s, int k, size_t start, size_t end) {
    array<int, 26> counts = {0};
    for (size_t i = start; i <= end; ++i) {
      counts[s[i] - 'a']++;
    }
    int max_length = 0;
    int interval_length = 0;
    size_t idx = start;
    while (idx <= end) {
      if (isValidCharacter(counts, s[idx], k)) {
        interval_length++;
      } else {
        if (interval_length > 0) {
          max_length = max(divideAndConquer(s, k, idx - interval_length, idx - 1), max_length);
        }
        interval_length = 0;
      }
      idx++;
    }
    if (interval_length == end - start + 1) {
      max_length = interval_length;
    } else if (interval_length > 0) {
      max_length = max(divideAndConquer(s, k, end - interval_length + 1, end), max_length);
    }
    return max_length;
  }

 private:
  bool isValidCharacter(const array<int, 26>& counts, char c, int k) {
    return counts[c - 'a'] >= k;
  }
};

int main() {
  Solution sol;
  string s;
  int k, expected;

  s = "aaabb", k = 3, expected = 3;
  EXPECT_EQ(expected, sol.longestSubstring(s, k));

  s = "ababbc", k = 2, expected = 5;
  EXPECT_EQ(expected, sol.longestSubstring(s, k));

  s = "aaabbb", k = 3, expected = 6;
  EXPECT_EQ(expected, sol.longestSubstring(s, k));

  s = "weitong", k = 2, expected = 0;
  EXPECT_EQ(expected, sol.longestSubstring(s, k));

  s = "ababacb", k = 3, expected = 0;
  EXPECT_EQ(expected, sol.longestSubstring(s, k));

  s = "bbaaacbd", k = 3, expected = 3;
  EXPECT_EQ(expected, sol.longestSubstring(s, k));

  exit(EXIT_SUCCESS);
}
