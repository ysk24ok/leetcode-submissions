#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// time complexity: O(s.size() * wordDict.size())
// space complexity: O(s.size() + 1)
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (size_t i = 0; i < s.size(); i++) {
      if (!dp[i]) continue;
      for (auto& word : wordDict) {
        if (s.substr(i, word.size()) == word) {
          dp[i + word.size()] = true;
        }
      }
    }
    return dp[dp.size()-1];
  }
};

int main() {
  Solution sol;
  string s;
  vector<string> word_dict;

  s = "leetcode";
  word_dict = {"leet", "code"};
  assert(sol.wordBreak(s, word_dict) == true);

  s = "applepenapple";
  word_dict = {"apple", "pen"};
  assert(sol.wordBreak(s, word_dict) == true);

  s = "catsandog";
  word_dict = {"cats", "dog", "sand", "and", "cat"};
  assert(sol.wordBreak(s, word_dict) == false);

  s = "cars";
  word_dict = {"cars", "ca", "rs"};
  assert(sol.wordBreak(s, word_dict) == true);

  s = "abcd";
  word_dict = {"a", "abc", "b", "cd"};
  assert(sol.wordBreak(s, word_dict) == true);
}
