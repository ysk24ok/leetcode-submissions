#include <gtest/gtest.h>

#include <array>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

constexpr size_t kAlphabetSize = 26;

class TrieNode {
 public:
  TrieNode() : target("") {
    nodes = {nullptr};
  }

  ~TrieNode() {
    for (size_t i = 0; i < kAlphabetSize; ++i) {
      if (nodes[i]) {
        delete nodes[i];
      }
    }
  }

  void add(const string& word, int idx) {
    if (idx == -1) {
      target = word;
      return;
    }
    int node_idx = word[idx] - 'a';
    if (!nodes[node_idx]) {
      nodes[node_idx] = new TrieNode();
    }
    nodes[node_idx]->add(word, idx-1);
  }

  void find(vector<string>& words_with_different_suffixes) {
    bool is_leaf = true;
    for (size_t i = 0; i < kAlphabetSize; ++i) {
      if (nodes[i]) {
        is_leaf = false;
        nodes[i]->find(words_with_different_suffixes);
      }
    }
    if (is_leaf) {
      words_with_different_suffixes.push_back(target);
    }
  }

 private:
  std::array<TrieNode*, kAlphabetSize> nodes;
  string target;
};

class Solution {
 public:
  int minimumLengthEncoding(vector<string>& words) {
    TrieNode* node = new TrieNode();
    for (const string& word : words) {
      node->add(word, word.size()-1);
    }
    vector<string> words_with_different_suffixes;
    node->find(words_with_different_suffixes);
    delete node;
    int ret = 0;
    for (const string& word : words_with_different_suffixes) {
      ret += word.size();
    }
    return ret + words_with_different_suffixes.size();
  }
};

int main() {
  Solution sol;
  vector<string> words;
  int expected;

  words = {"time", "me", "bell"}, expected = 10;
  EXPECT_EQ(expected, sol.minimumLengthEncoding(words));

  words = {"t"}, expected = 2;
  EXPECT_EQ(expected, sol.minimumLengthEncoding(words));

  exit(EXIT_SUCCESS);
}
