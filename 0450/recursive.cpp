#include <cstdlib>
#include <string>

#include "gtest/gtest.h"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
      return nullptr;
    } else if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if (!root->left) {
        TreeNode* new_root = root->right;
        delete root;
        return new_root;
      } else if (!root->right) {
        TreeNode* new_root = root->left;
        delete root;
        return new_root;
      } else {
        TreeNode* node = findMinNode(root->right);
        root->val = node->val;
        root->right = deleteNode(root->right, root->val);
      }
    }
    return root;
  }

  TreeNode* findMinNode(TreeNode* node) {
    while (node->left) {
      node = node->left;
    }
    return node;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  TreeNode* got;
  int key;

  //     5             5
  //    / \           / \
  //   3   6    ->   4   6
  //  / \   \       /     \
  // 2   4   7     2       7
  root = CreateTreeNode("5 3 6 2 4 # 7");
  key = 3;
  got = sol.deleteNode(root, key);
  EXPECT_EQ(5, got->val);
  EXPECT_EQ(4, got->left->val);
  EXPECT_EQ(6, got->right->val);
  EXPECT_EQ(2, got->left->left->val);
  EXPECT_EQ(7, got->right->right->val);
  DeleteTreeNode(got);

  root = CreateTreeNode("5 3 6 2 4 # 7");
  key = 0;
  got = sol.deleteNode(root, key);
  EXPECT_EQ(5, got->val);
  EXPECT_EQ(3, got->left->val);
  EXPECT_EQ(6, got->right->val);
  EXPECT_EQ(2, got->left->left->val);
  EXPECT_EQ(4, got->left->right->val);
  EXPECT_EQ(7, got->right->right->val);
  DeleteTreeNode(got);

  root = CreateTreeNode("0");
  key = 0;
  got = sol.deleteNode(root, key);
  EXPECT_FALSE(got);

  //      6            6            6
  //     /            /            /
  //    3            2            4
  //  /   \   ->   /   \   or   /   \
  // 1     5      1     5      1     5
  //  \   /            /        \
  //   2 4            4          2
  root = CreateTreeNode("6 3 # 1 5 # 2 4");
  key = 3;
  got = sol.deleteNode(root, key);
  EXPECT_EQ(6, got->val);
  EXPECT_EQ(4, got->left->val);
  EXPECT_EQ(1, got->left->left->val);
  EXPECT_EQ(5, got->left->right->val);
  EXPECT_EQ(2, got->left->left->right->val);
  DeleteTreeNode(got);

  exit(EXIT_SUCCESS);
}
