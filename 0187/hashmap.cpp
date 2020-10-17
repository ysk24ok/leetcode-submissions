#include <gtest/gtest.h>

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int SEQ_LENGTH = 10;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ret;
    if (s.size() < SEQ_LENGTH) { return ret; }
    unordered_map<string, int> counts;
    string substr(SEQ_LENGTH, ' ');
    for (size_t i = 0; i < s.size()-(SEQ_LENGTH-1); ++i) {
      substr = s.substr(i, SEQ_LENGTH);
      counts[substr]++;
      if (counts[substr] == 2) {
        ret.push_back(substr);
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  string s;
  vector<string> expected;

  s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  expected = {"AAAAACCCCC", "CCCCCAAAAA"};
  EXPECT_EQ(expected, sol.findRepeatedDnaSequences(s));

  s = "AAAAAAAAAAAAA";
  expected = {"AAAAAAAAAA"};
  EXPECT_EQ(expected, sol.findRepeatedDnaSequences(s));

  s = "";
  expected = {};
  EXPECT_EQ(expected, sol.findRepeatedDnaSequences(s));

  s = "AAAAACCCCC";
  expected = {};
  EXPECT_EQ(expected, sol.findRepeatedDnaSequences(s));
}
