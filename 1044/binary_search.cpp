#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

constexpr int radix = 101;
constexpr int mod = 1e9 + 7;

class Solution {
 public:
  string longestDupSubstring(string S) {
    int left = 0, right = S.size() - 1;
    int start = 0, max_len = 0;
    while (left < right) {
      int len = (right - left) / 2 + left;
      // longer duplicate may exists
      int pos = find(S, len);
      if (pos >= 0) {
        start = pos;
        max_len = len;
        left = len + 1;
      } else {
        right = len;
      }
    }
    return S.substr(start, max_len);
  }

  int find(const string& S, int len) {
    unordered_map<int, vector<int>> map;
    long h = hash(S, len);
    map[h].push_back(0);
    long radix_left = 1;
    for (int i = 1; i < len; ++i) {
      radix_left *= radix;
      radix_left %= mod;
    }
    for (int i = 1; i + len <= S.size(); ++i) {
      // rolling hash
      h += mod;
      h -= static_cast<int>(S[i-1]) * radix_left % mod;
      h *= radix;
      h %= mod;
      h += static_cast<int>(S[i+len-1]);
      h %= mod;
      if (map.find(h) != map.end()) {
        for (const int& j : map[h]) {
          // different strings can be same hash value,
          // so compare the string itself
          if (compare(S, i, j, len)) {
            return i;
          }
        }
      }
      map[h].push_back(i);
    }
    return -1;
  }

  long hash(const string& S, int len) {
    long h = 0;
    for (int i = 0; i < len; ++i) {
      h *= radix;
      h += static_cast<int>(S[i]);
      h %= mod;
    }
    return h;
  }

  bool compare(const string& S, int i, int j, int len) {
    for (int k = 0; k < len; ++k) {
      if (S[i+k] != S[j+k]) { return false; }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string S, expected;

  S = "banana";
  expected = "ana";
  EXPECT_EQ(expected, sol.longestDupSubstring(S));

  S = "abcd";
  expected = "";
  EXPECT_EQ(expected, sol.longestDupSubstring(S));

  exit(EXIT_SUCCESS);
}
