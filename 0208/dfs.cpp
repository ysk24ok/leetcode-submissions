#include <array>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int kAlphabetSize = 26;

class Trie {
  struct TrieNode {
   public:
    TrieNode(bool end=false) : end(end) {
      for (size_t i = 0; i < kAlphabetSize; i++) pointers[i] = nullptr;
    }
    std::array<TrieNode*, kAlphabetSize> pointers;
    bool end;
  };

 public:
  /** Initialize your data structure here. */
  Trie() : root(new TrieNode()) {}

  ~Trie() {
    deleteNodes(root);
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    insertDfs(root, word, 0);
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    return searchDfs(root, word, 0);
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    return startsWithDfs(root, prefix, 0);
  }

 private:
  void insertDfs(TrieNode* node, const string& word, size_t word_idx) {
    int idx = getIndex(word[word_idx]);
    if (!node->pointers[idx]) node->pointers[idx] = new TrieNode();
    if (word_idx == word.size() - 1) {
      node->pointers[idx]->end = true;
      return;
    }
    insertDfs(node->pointers[idx], word, word_idx+1);
  }

  bool searchDfs(TrieNode* node, const string& word, size_t word_idx) {
    if (word_idx >= word.size()) return true;
    int idx = getIndex(word[word_idx]);
    if (!node->pointers[idx]) return false;
    if (word_idx == word.size() - 1) return node->pointers[idx]->end;
    return searchDfs(node->pointers[idx], word, word_idx+1);
  }

  bool startsWithDfs(TrieNode* node, const string& word, size_t word_idx) {
    int idx = getIndex(word[word_idx]);
    string a = node->pointers[idx] ? "true" : "false";
    if (!node->pointers[idx]) return false;
    if (word_idx == word.size() - 1) return true;
    return startsWithDfs(node->pointers[idx], word, word_idx+1);
  }

  int getIndex(const char& c) {
    return int(c) - int('a');
  }

  void deleteNodes(TrieNode* node) {
    for (size_t i = 0; i < kAlphabetSize; i++) {
      TrieNode* ptr = node->pointers[i];
      if (ptr) {
        deleteNodes(ptr);
        delete node->pointers[i];
      }
    }
  }

  TrieNode* root;
};

int main() {
  Trie* trie = new Trie();
  trie->insert("apple");
  assert(trie->search("apple"));
  assert(!trie->search("app"));
  assert(trie->startsWith("app"));
  trie->insert("app");
  assert(trie->search("app"));

  assert(!trie->search("beef"));
  assert(!trie->startsWith("be"));
  trie->insert("beef");
  assert(trie->search("beef"));
  assert(trie->startsWith("beef"));
  assert(trie->startsWith("bee"));
  assert(trie->startsWith("be"));
  assert(trie->startsWith("b"));
  delete trie;
}
