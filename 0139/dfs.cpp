#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// XXX: TLE
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return dfs(0, s, wordDict);
  }

  bool dfs(size_t start_idx, string& s, vector<string>& wordDict) {
    if (start_idx == s.size()) return true;
    for (auto& word : wordDict) {
      if (s.substr(start_idx, word.size()) == word) {
        bool ret = dfs(start_idx + word.size(), s, wordDict);
        if (ret) return true;
      }
    }
    return false;
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
