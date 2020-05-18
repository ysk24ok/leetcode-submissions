#include <string>
#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> count;
    for (const char& c : p) { count[c]++; }
    vector<int> ret;
    const size_t m = s.size(), n = p.size();
    int diff = n;
    size_t start = 0, end = 0;
    for (end = 0; end < n; ++end) {
      count[s[end]]--;
      if (count[s[end]] >= 0) { diff--; }
    }
    // Now, 'start' is at 0, 'end' is at n, and the window is at [0,n)
    if (diff == 0) { ret.push_back(start); }
    while (end < m) {
      // out of the window
      const char& start_char = s[start];
      if (count[start_char] >= 0) { diff++; }
      count[start_char]++;
      ++start;
      // inside the window
      const char& end_char = s[end];
      count[end_char]--;
      if (count[end_char] >= 0) { diff--; }
      ++end;
      // the window is at [i,n+i)
      if (diff == 0) { ret.push_back(start); }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s, p;
  vector<int> got, expected;

  s = "cbaebabacd", p = "abc";
  expected = {0,6};
  got = sol.findAnagrams(s, p);
  assert(expected.size() == got.size());
  for (size_t i = 0, m = expected.size(); i < m; ++i) {
    EXPECT_EQ(expected[i], got[i]);
  }

  s = "abab", p = "ab";
  expected = {0,1,2};
  got = sol.findAnagrams(s, p);
  assert(expected.size() == got.size());
  for (size_t i = 0, m = expected.size(); i < m; ++i) {
    EXPECT_EQ(expected[i], got[i]);
  }

  s = "cabcba", p = "abc";
  expected = {0,1,3};
  got = sol.findAnagrams(s, p);
  assert(expected.size() == got.size());
  for (size_t i = 0, m = expected.size(); i < m; ++i) {
    EXPECT_EQ(expected[i], got[i]);
  }

  s = "aaaaaaaaaa", p = "aaaaaaaaaaaaa";
  expected = {};
  got = sol.findAnagrams(s, p);
  assert(expected.size() == got.size());
  for (size_t i = 0, m = expected.size(); i < m; ++i) {
    EXPECT_EQ(expected[i], got[i]);
  }
}
