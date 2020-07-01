#include <cassert>
#include <cstdlib>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"

using namespace std;

class TrieNode {
 public:
  TrieNode() : end_(false), word_(""), nodes_() {}

  bool contains(const char& c) const {
    return nodes_.find(c) != nodes_.end();
  }

  bool isEnd() const {
    return end_;
  }

  string getWord() const {
    return word_;
  }

  void add(const string& word, size_t idx) {
    if (idx == word.size()) {
      end_ = true;
      word_ = word;
      return;
    }
    const char& c = word[idx];
    if (!contains(c)) {
      nodes_[c] = unique_ptr<TrieNode>(new TrieNode());
    }
    nodes_[c]->add(word, idx+1);
  }

  bool search(const string& word, size_t idx) const {
    if (idx >= word.size()) {
      return true;
    }
    const char& c = word[idx];
    if (!contains(c)) {
      return false;
    }
    return nodes_.at(c)->search(word, idx+1);
  }

  const unique_ptr<TrieNode>& getNode(const char& c) const {
    assert(contains(c));
    return nodes_.at(c);
  }

 private:
  bool end_;
  string word_;
  unordered_map<char, unique_ptr<TrieNode>> nodes_;
};

class Trie {
 public:
  Trie() : node_(new TrieNode()) {}

  void add(const string& word) {
    node_->add(word, 0);
  }

  bool search(const string& word) const {
    return node_->search(word, 0);
  }

  const unique_ptr<TrieNode>& getNode() const {
    return node_;
  }

 private:
  unique_ptr<TrieNode> node_;
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Trie trie;
    for (const auto& word : words) {
      trie.add(word);
    }
    const size_t m = board.size();
    if (m == 0) {
      return {};
    }
    const size_t n = board[0].size();
    unordered_set<string> ret;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        recursive(board, i, j, trie.getNode(), 0, visited, ret);
      }
    }
    vector<string> ret_vec;
    ret_vec.insert(ret_vec.end(), ret.begin(), ret.end());
    return ret_vec;
  }

  void recursive(const vector<vector<char>>& board, size_t i, size_t j,
                 const unique_ptr<TrieNode>& node, size_t idx,
                 vector<vector<bool>>& visited, unordered_set<string>& ret) {
    const size_t m = board.size(), n = board[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return;
    }
    if (visited[i][j]) {
      return;
    }
    const char& c = board[i][j];
    if (!node->contains(c)) {
      return;
    }
    const unique_ptr<TrieNode>& next_node = node->getNode(c);
    if (next_node->isEnd()) {
      ret.insert(next_node->getWord());
    }
    visited[i][j] = true;
    recursive(board, i-1, j, next_node, idx+1, visited, ret);
    recursive(board, i+1, j, next_node, idx+1, visited, ret);
    recursive(board, i, j-1, next_node, idx+1, visited, ret);
    recursive(board, i, j+1, next_node, idx+1, visited, ret);
    visited[i][j] = false;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> board;
  vector<string> words, expected;

  board = {
    {'o','a','a','n'},
    {'e','t','a','e'},
    {'i','h','k','r'},
    {'i','f','l','v'}
  };
  words = {"oath","pea","eat","rain"};
  expected = {"eat", "oath"};
  EXPECT_EQ(expected, sol.findWords(board, words));

  board = {
    {'a', 'a'}
  };
  words = {"a"};
  expected = {"a"};
  EXPECT_EQ(expected, sol.findWords(board, words));

  exit(EXIT_SUCCESS);
}
