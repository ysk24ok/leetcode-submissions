#include <gtest/gtest.h>

#include <string>
#include <unordered_set>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> values;
    return dfs(root, k, values);
  }
  
  bool dfs(TreeNode* node, int k, unordered_set<int>& values) {
    if (!node) {
      return false;
    }
    if (values.find(k - node->val) != values.end()) {
      return true;
    }
    values.insert(node->val);
    return dfs(node->left, k, values) || dfs(node->right, k, values);
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int k;
  bool expected;

  root = CreateTreeNode("5 3 6 2 4 # 7"), k = 9, expected = true;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  root = CreateTreeNode("5 3 6 2 4 # 7"), k = 28, expected = false;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  root = CreateTreeNode("2 1 3"), k = 4, expected = true;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  root = CreateTreeNode("2 1 3"), k = 1, expected = false;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  root = CreateTreeNode("2 1 3"), k = 3, expected = true;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
