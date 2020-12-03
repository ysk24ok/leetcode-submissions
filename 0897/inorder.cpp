#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* increasingBST(TreeNode* root) {
    if (!root) { return nullptr; }
    TreeNode node(-1);
    inorderTraversal(root, &node);
    return node.right;
  }

  TreeNode* inorderTraversal(TreeNode* node, TreeNode* prev) {
    if (node->left) {
      prev = inorderTraversal(node->left, prev);
      node->left = nullptr;
    }
    prev->right = node;
    if (node->right) {
      node = inorderTraversal(node->right, node);
    }
    return node;
  }
};

int main() {
  Solution sol;
  TreeNode *root, *got;
  root = CreateTreeNode("5 1 7");
  got = sol.increasingBST(root);
  EXPECT_EQ(1, got->val);
  EXPECT_FALSE(got->left);
  EXPECT_EQ(5, got->right->val);
  EXPECT_FALSE(got->right->left);
  EXPECT_EQ(7, got->right->right->val);
  EXPECT_FALSE(got->right->right->left);
  EXPECT_FALSE(got->right->right->right);
  DeleteTreeNode(got);

  exit(EXIT_SUCCESS);
}
