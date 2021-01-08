#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    size_t idx1 = 0, subidx1 = 0, idx2 = 0, subidx2 = 0;
    while (idx1 < word1.size() && idx2 < word2.size()) {
      if (word1[idx1][subidx1] != word2[idx2][subidx2]) {
        return false;
      }
      subidx1++;
      if (subidx1 >= word1[idx1].size()) {
        idx1++;
        subidx1 = 0;
      }
      subidx2++;
      if (subidx2 >= word2[idx2].size()) {
        idx2++;
        subidx2 = 0;
      }
    }
    return idx1 >= word1.size() && idx2 >= word2.size();
  }
};

int main() {
  Solution sol;
  vector<string> word1, word2;
  bool expected;

  word1 = {"ab", "c"}, word2 = {"a", "bc"}, expected = true;
  EXPECT_EQ(expected, sol.arrayStringsAreEqual(word1, word2));

  word1 = {"a", "cb"}, word2 = {"ab", "c"}, expected = false;
  EXPECT_EQ(expected, sol.arrayStringsAreEqual(word1, word2));

  word1 = {"abc", "d", "defg"}, word2 = {"abcddefg"}, expected = true;
  EXPECT_EQ(expected, sol.arrayStringsAreEqual(word1, word2));

  word1 = {"ab", "c"}, word2 = {"a", "b"}, expected = false;
  EXPECT_EQ(expected, sol.arrayStringsAreEqual(word1, word2));

  exit(EXIT_SUCCESS);
}
