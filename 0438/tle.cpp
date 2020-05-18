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
    if (m < n) { return ret; }
    for (size_t i = 0; i < m - n + 1; ++i) {
      if (isAnagram(s, count, n, i)) {
        ret.push_back(i);
      }
    }
    return ret;
  }

  bool isAnagram(const string& s, unordered_map<char, int> count, const size_t size, size_t& start) {
    for (size_t i = start; i < start + size; ++i) {
      const char& c = s[i];
      if (count.find(c) == count.end()) {
        start = i;
        return false;
      }
      if (count[c] == 0) { return false; }
      count[c]--;
    }
    for (const auto& pair : count) {
      if (pair.second > 0) { return false; }
    }
    return true;
  }
};

void expect(const vector<int>& expected, const vector<int>& got) {
  ASSERT_EQ(expected.size(), got.size());
  for (size_t i = 0, m = expected.size(); i < m; ++i) {
    EXPECT_EQ(expected[i], got[i]);
  }
}

int main() {
  Solution sol;
  string s, p;
  vector<int> got, expected;

  s = "cbaebabacd", p = "abc";
  expected = {0,6};
  got = sol.findAnagrams(s, p);
  expect(expected, got);

  s = "abab", p = "ab";
  expected = {0,1,2};
  got = sol.findAnagrams(s, p);
  expect(expected, got);

  s = "cabcba", p = "abc";
  expected = {0,1,3};
  got = sol.findAnagrams(s, p);
  expect(expected, got);

  s = "aaaaaaaaaa", p = "aaaaaaaaaaaaa";
  expected = {};
  got = sol.findAnagrams(s, p);
  expect(expected, got);

  return 0;
}
