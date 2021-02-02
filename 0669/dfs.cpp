#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) { return nullptr; }
    if (root->val < low) {
      return trimBST(root->right, low, high);
    } else if (high < root->val) {
      return trimBST(root->left, low, high);
    } else {
      root->left = trimBST(root->left, low, high);
      root->right = trimBST(root->right, low, high);
      return root;
    }
  }
};

int main() {
  Solution sol;
  TreeNode *root, *got;
  int low, high;

  root = CreateTreeNode("1 0 2"), low = 1, high = 2;
  got = sol.trimBST(root, low, high);
  EXPECT_EQ(1, got->val);
  EXPECT_FALSE(got->left);
  EXPECT_EQ(2, got->right->val);
  EXPECT_FALSE(got->right->left);
  EXPECT_FALSE(got->right->right);
  DeleteTreeNode(root);

  root = CreateTreeNode("3 0 4 # 2 # # 1"), low = 1, high = 3;
  got = sol.trimBST(root, low, high);
  EXPECT_EQ(3, got->val);
  EXPECT_EQ(2, got->left->val);
  EXPECT_FALSE(got->right);
  EXPECT_EQ(1, got->left->left->val);
  EXPECT_FALSE(got->left->right);
  EXPECT_FALSE(got->left->left->left);
  EXPECT_FALSE(got->left->left->right);
  DeleteTreeNode(root);

  root = CreateTreeNode("1"), low = 1, high = 2;
  got = sol.trimBST(root, low, high);
  EXPECT_EQ(1, got->val);
  EXPECT_FALSE(got->left);
  EXPECT_FALSE(got->right);
  DeleteTreeNode(root);

  root = CreateTreeNode("1 # 2"), low = 1, high = 3;
  got = sol.trimBST(root, low, high);
  EXPECT_EQ(1, got->val);
  EXPECT_FALSE(got->left);
  EXPECT_EQ(2, got->right->val);
  EXPECT_FALSE(got->right->left);
  EXPECT_FALSE(got->right->right);
  DeleteTreeNode(root);

  root = CreateTreeNode("1 # 2"), low = 2, high = 4;
  got = sol.trimBST(root, low, high);
  EXPECT_EQ(2, got->val);
  EXPECT_FALSE(got->left);
  EXPECT_FALSE(got->right);
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
