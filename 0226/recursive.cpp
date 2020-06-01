#include <cstdlib>

#include "gtest/gtest.h"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) { return nullptr; }
    return dfs(root);
  }

  TreeNode* dfs(TreeNode* node) {
    if (!node) { return nullptr; }
    TreeNode* new_node = new TreeNode(node->val);
    new_node->right = dfs(node->left);
    new_node->left = dfs(node->right);
    return new_node;
  }
};

int main() {
  Solution sol;
  TreeNode* root = nullptr;
  TreeNode* got = nullptr;

  root = CreateTreeNode("4 2 7 1 3 6 9 ;");
  got = sol.invertTree(root);
  EXPECT_EQ(4, got->val);
  EXPECT_EQ(7, got->left->val);
  EXPECT_EQ(2, got->right->val);
  EXPECT_EQ(9, got->left->left->val);
  EXPECT_EQ(6, got->left->right->val);
  EXPECT_EQ(3, got->right->left->val);
  EXPECT_EQ(1, got->right->right->val);

  exit(EXIT_SUCCESS);
}
