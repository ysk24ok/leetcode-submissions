#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    const size_t dic_size = d.size();
    vector<size_t> indices(dic_size);
    for (const char& c : s) {
      for (size_t i = 0; i < dic_size; ++i) {
        const string& word = d[i];
        if (indices[i] == word.size()) {
          continue;
        }
        if (word[indices[i]] == c) {
          indices[i]++;
        }
      }
    }
    size_t max_word_size = 0;
    string ret = "";
    for (size_t i = 0; i < dic_size; ++i) {
      const string& word = d[i];
      size_t word_size = word.size();
      if (indices[i] < word_size) {
        continue;
      }
      if (word_size > max_word_size) {
        max_word_size = word_size;
        ret = word;
      } else if (word_size == max_word_size) {
        ret = lexicographical_compare(word.begin(), word.end(), ret.begin(), ret.end()) ? word : ret;
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s;
  vector<string> d;
  string expected;

  s = "abpcplea", d = {"ale", "apple", "monkey", "plea"}, expected = "apple";
  EXPECT_EQ(expected, sol.findLongestWord(s, d));

  s = "abpcplea", d = {"a", "b", "c"}, expected = "a";
  EXPECT_EQ(expected, sol.findLongestWord(s, d));

  // Failed to deal with the case where `s` and a word in `d` are the same size
  s = "aaa", d = {"aaa", "aa", "a"}, expected = "aaa";
  EXPECT_EQ(expected, sol.findLongestWord(s, d));

  // Failed to return the word with the smallest lexicographical order
  s = "bab", d = {"ba", "ab", "a", "b"}, expected = "ab";
  EXPECT_EQ(expected, sol.findLongestWord(s, d));

  exit(EXIT_SUCCESS);
}
