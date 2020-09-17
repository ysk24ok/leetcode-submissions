#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

struct TrieNode {
 TrieNode() {
   nodes[0] = nullptr;
   nodes[1] = nullptr;
 }

 TrieNode* nodes[2];
};

void DeleteTrieNode(TrieNode* node) {
  if (!node) { return; }
  DeleteTrieNode(node->nodes[0]);
  DeleteTrieNode(node->nodes[1]);
  delete node;
}

class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    TrieNode* root = createTrieNode(nums);
    int ret = 0;
    for (const int& num : nums) {
      TrieNode* curr_node = root;
      int curr_sum = 0;
      for (int i = 31; i >= 0; --i) {
        int curr_bit = (num >> i) & 1;
        if (curr_node->nodes[curr_bit ^ 1]) {
          curr_sum += (1 << i);
          curr_node = curr_node->nodes[curr_bit ^ 1];
        } else {
          curr_node = curr_node->nodes[curr_bit];
        }
      }
      ret = max(ret, curr_sum);
    }
    DeleteTrieNode(root);
    return ret;
  }

 private:
  TrieNode* createTrieNode(const vector<int>& nums) {
    TrieNode* root = new TrieNode();
    for (const int& num : nums) {
      TrieNode* curr_node = root;
      for (int i = 31; i >= 0; --i) {
        int curr_bit = (num >> i) & 1;
        if (!curr_node->nodes[curr_bit]) {
          curr_node->nodes[curr_bit] = new TrieNode();
        }
        curr_node = curr_node->nodes[curr_bit];
      }
    }
    return root;
  }
};

int main() {
  Solution sol;
  vector<int> nums;
  int expected;

  //  3: 00011
  // 10: 01010
  //  5: 00101
  // 25: 11001
  //  2: 00010
  //  8: 01000
  nums = {3, 10, 5, 25, 2, 8};
  expected = 28;
  EXPECT_EQ(expected, sol.findMaximumXOR(nums));

  exit(EXIT_SUCCESS);
}
