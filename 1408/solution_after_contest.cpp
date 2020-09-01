#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> ret;
    for (size_t i = 0, size = words.size(); i < size; ++i) {
      for (size_t j = 0; j < size; ++j) {
        if (i == j) { continue; }
        if (words[j].find(words[i]) != string::npos) {
          ret.push_back(words[i]);
          break;
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<string> words, got, expected;

  words = {"mass","as","hero","superhero"};
  got = sol.stringMatching(words);
  expected = {"as", "hero"};
  EXPECT_EQ(expected, got);

  words = {"leetcode","et","code"};
  got = sol.stringMatching(words);
  expected = {"et", "code"};
  EXPECT_EQ(expected, got);

  words = {"blue","green","bu"};
  got = sol.stringMatching(words);
  EXPECT_EQ(0ul, got.size());

  words = {"leetcoder","leetcode","od","hamlet","am"};
  got = sol.stringMatching(words);
  expected = {"leetcode", "od", "am"};
  EXPECT_EQ(expected, got);
}
