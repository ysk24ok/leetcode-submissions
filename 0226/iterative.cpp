#include <cstdlib>
#include <queue>

#include "gtest/gtest.h"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) { return nullptr; }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      TreeNode* tmp = node->right;
      node->right = node->left;
      node->left = tmp;
      if (node->left) { q.push(node->left); }
      if (node->right) { q.push(node->right); }
    }
    return root;
  }
};

int main() {
  Solution sol;
  TreeNode* root = nullptr;
  TreeNode* got = nullptr;

  root = CreateTreeNode("4 2 7 1 3 6 9");
  got = sol.invertTree(root);
  EXPECT_EQ(4, got->val);
  EXPECT_EQ(7, got->left->val);
  EXPECT_EQ(2, got->right->val);
  EXPECT_EQ(9, got->left->left->val);
  EXPECT_EQ(6, got->left->right->val);
  EXPECT_EQ(3, got->right->left->val);
  EXPECT_EQ(1, got->right->right->val);

  EXPECT_FALSE(sol.invertTree(nullptr));

  exit(EXIT_SUCCESS);
}
