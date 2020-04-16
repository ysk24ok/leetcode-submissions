#include <string>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

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
  ExpectVectorUnorderedEqual(expected, got);

  words = {"leetcode","et","code"};
  got = sol.stringMatching(words);
  expected = {"et", "code"};
  ExpectVectorUnorderedEqual(expected, got);

  words = {"blue","green","bu"};
  got = sol.stringMatching(words);
  ExpectEqual(0ul, got.size());

  words = {"leetcoder","leetcode","od","hamlet","am"};
  got = sol.stringMatching(words);
  expected = {"leetcode", "od", "am"};
  ExpectVectorUnorderedEqual(expected, got);
}
