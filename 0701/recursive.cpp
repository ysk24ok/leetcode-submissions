#include <gtest/gtest.h>

#include <cstdlib>

#include <leetcode/tree.hpp>

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
      return new TreeNode(val);
    }
    insert(root, val);
    return root;
  }

  void insert(TreeNode* node, int val) {
    if (val < node->val) {
      if (!node->left) {
        node->left = new TreeNode(val);
      } else {
        insertIntoBST(node->left, val);
      }
    } else {
      if (!node->right) {
        node->right = new TreeNode(val);
      } else {
        insertIntoBST(node->right, val);
      }
    }
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int val;
  TreeNode* got;

  root = CreateTreeNode("4 2 7 1 3"), val = 5;
  got = sol.insertIntoBST(root, val);
  EXPECT_EQ(4, got->val);
  EXPECT_EQ(2, got->left->val);
  EXPECT_EQ(7, got->right->val);
  EXPECT_EQ(1, got->left->left->val);
  EXPECT_EQ(3, got->left->right->val);
  EXPECT_EQ(5, got->right->left->val);
  DeleteTreeNode(got);

  val = 1;
  got = sol.insertIntoBST(nullptr, val);
  EXPECT_EQ(1, got->val);
  DeleteTreeNode(got);

  exit(EXIT_SUCCESS);
}
