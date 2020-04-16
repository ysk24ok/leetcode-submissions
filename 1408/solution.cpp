#include <set>
#include <string>
#include <vector>

#include "leetcode/assert.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    set<string> s;
    for (size_t i = 0; i < words.size() - 1; ++i) {
      for (size_t j = i + 1; j < words.size(); ++j) {
        if (i == j) continue;
        if (words[i].size() > words[j].size()) {
          if (isSubstring(words[j], words[i])) s.insert(words[j]);
        } else if (words[i].size() < words[j].size()) {
          if (isSubstring(words[i], words[j])) s.insert(words[i]);
        } else {
          if (words[i] == words[j]) assert(false);
        }
      }
    }
    return vector<string>(s.begin(), s.end());
  }

  bool isSubstring(const string& s1, const string& s2) {
    assert(s1.size() <= s2.size());
    bool ret = false;
    for (size_t s = 0; s < s2.size() - s1.size() + 1; ++s) {
      bool is_substring = true;
      for (size_t i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[s + i]) is_substring = false;
      }
      ret |= is_substring;
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
