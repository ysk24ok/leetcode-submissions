#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    unordered_map<char, size_t> freq_s = countFreq(s);
    unordered_map<char, size_t> freq_t = countFreq(t);
    return check(freq_s, freq_t) && check(freq_t, freq_s);
  }

  unordered_map<char, size_t> countFreq(const string& s) {
    unordered_map<char, size_t> freq;
    for (const char& c : s) {
      freq[c]++;
    }
    return freq;
  }

  bool check(const unordered_map<char, size_t>& freq1, const unordered_map<char, size_t>& freq2) {
    for (const auto& p : freq1) {
      if (freq2.find(p.first) == freq2.end() || freq2.at(p.first) != p.second) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution sol;
  string s, t;
  bool expected;

  s = "anagram", t = "nagaram", expected = true;
  EXPECT_EQ(expected, sol.isAnagram(s, t));

  s = "anagram", t = "nagarama", expected = false;
  EXPECT_EQ(expected, sol.isAnagram(s, t));

  exit(EXIT_SUCCESS);
}
