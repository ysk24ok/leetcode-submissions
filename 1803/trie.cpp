#include <gtest/gtest.h>

#include <array>
#include <cstdlib>
#include <vector>

using namespace std;

class TrieNode {
 public:
  TrieNode() : count_(0), nodes_({nullptr}){}

  ~TrieNode() {
    if (nodes_[0]) { delete nodes_[0]; }
    if (nodes_[1]) { delete nodes_[1]; }
  }

  void add(int val) {
    TrieNode* node = this;
    for (int i = 31; i >= 0; --i) {
      int bit = (val >> i) & 1;
      if (!node->nodes_[bit]) {
        node->nodes_[bit] = new TrieNode();
      }
      node->nodes_[bit]->count_++;
      node = node->nodes_[bit];
    }
  }

  int count(int val, int high) {
    int ret = 0;
    TrieNode* node = this;
    for (int i = 31; i >= 0; --i) {
      if (!node) {
        break;
      }
      int bit = (val >> i) & 1;
      if ((high >> i) & 1) {
        if (node->nodes_[bit]) {
          ret += node->nodes_[bit]->count_;
        }
        node = node->nodes_[bit ^ 1];
      } else {
        node = node->nodes_[bit];
      }
    }
    return ret;
  }

 private:
  int count_;
  array<TrieNode*, 2> nodes_;
};

class Solution {
 public:
  int countPairs(vector<int>& nums, int low, int high) {
    TrieNode* node = new TrieNode();
    int ret = 0;
    for (const int& num : nums) {
      ret += node->count(num, high + 1) - node->count(num, low);
      node->add(num);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int low, high, expected;

  nums = {1, 4, 2, 7}, low = 2, high = 6, expected = 6;
  EXPECT_EQ(expected, sol.countPairs(nums, low, high));

  nums = {9, 8, 4, 2, 1}, low = 5, high = 14, expected = 8;
  EXPECT_EQ(expected, sol.countPairs(nums, low, high));

  exit(EXIT_SUCCESS);
}
