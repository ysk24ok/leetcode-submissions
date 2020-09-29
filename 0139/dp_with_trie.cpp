#include <gtest/gtest.h>

#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
 public:
  TrieNode() {
    for (size_t i = 0; i < 26; ++i) {
      nextNodes[i] = nullptr;
    }
    endsWith = false;
  };

  TrieNode* nextNodes[26];
  bool endsWith;

  bool search(const string& word, size_t idx) {
    if (idx == word.size()) {
      return endsWith;
    }
    int node_idx = int(word[idx]) - int('a');
    if (!nextNodes[node_idx]) { return false; }
    return nextNodes[node_idx]->search(word, idx+1);
  }
};

void DeleteTrieNode(TrieNode* node) {
  if (!node) { return; }
  for (size_t i = 0; i < 26; ++i) {
    DeleteTrieNode(node->nextNodes[i]);
  }
  delete node;
}


class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    TrieNode* root = new TrieNode();
    TrieNode* node;
    for (const string& word : wordDict) {
      node = root;
      for (const char& c : word) {
        int idx = int(c) - int('a');
        if (!node->nextNodes[idx]) {
          node->nextNodes[idx] = new TrieNode();
        }
        node = node->nextNodes[idx];
      }
      node->endsWith = true;
    }
    const size_t n = s.size();
    vector<bool> dp(n + 1, false);
    //  leetcode
    // tffftffft
    dp[0] = true;
    for (size_t i = 1; i <= n; ++i) {
      for (size_t j = 1; j <= i; ++j) {
        if (!dp[j-1]) { continue; }
        size_t start = j - 1, end = i - 1;
        if (root->search(s.substr(start, end - start + 1), 0)) {
          dp[i] = true;
        }
      }
    }
    DeleteTrieNode(root);
    return dp[n];
  }
};

int main() {
  Solution sol;
  string s;
  vector<string> word_dict;

  s = "leetcode";
  word_dict = {"leet", "code"};
  EXPECT_TRUE(sol.wordBreak(s, word_dict));

  s = "applepenapple";
  word_dict = {"apple", "pen"};
  EXPECT_TRUE(sol.wordBreak(s, word_dict));

  s = "catsandog";
  word_dict = {"cats", "dog", "sand", "and", "cat"};
  EXPECT_FALSE(sol.wordBreak(s, word_dict));

  s = "cars";
  word_dict = {"cars", "ca", "rs"};
  EXPECT_TRUE(sol.wordBreak(s, word_dict));

  s = "abcd";
  word_dict = {"a", "abc", "b", "cd"};
  EXPECT_TRUE(sol.wordBreak(s, word_dict));

  exit(EXIT_SUCCESS);
}
