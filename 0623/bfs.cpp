#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if (d == 1) {
      TreeNode* new_root = new TreeNode(v);
      new_root->left = root;
      return new_root;
    }
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
      TreeNode* node = q.front().first;
      int depth = q.front().second;
      q.pop();
      if (depth + 1 == d) {
        TreeNode* new_left = new TreeNode(v);
        new_left->left = node->left;
        node->left = new_left;
        TreeNode* new_right = new TreeNode(v);
        new_right->right = node->right;
        node->right = new_right;
      } else {
        if (node->left) {
          q.push({node->left, depth + 1});
        }
        if (node->right) {
          q.push({node->right, depth + 1});
        }
      }
    }
    return root;
  }
};

int main() {
  Solution sol;
  TreeNode *root, *got;
  int v, d;

  /**
   *      4                 4
   *    /   \              / \
   *   2     6   =>       1   1
   *  / \   /            /     \
   * 3   1 5            2       6
   *                   / \     /
   *                  3   1   5
   */
  root = CreateTreeNode("4 2 6 3 1 5"), v = 1, d = 2;
  got = sol.addOneRow(root, v, d);
  EXPECT_EQ(4, got->val);
  EXPECT_EQ(1, got->left->val);
  EXPECT_EQ(1, got->right->val);
  EXPECT_EQ(2, got->left->left->val);
  EXPECT_EQ(6, got->right->right->val);
  EXPECT_EQ(3, got->left->left->left->val);
  EXPECT_EQ(1, got->left->left->right->val);
  EXPECT_EQ(5, got->right->right->left->val);
  DeleteTreeNode(got);

  /**
   *     4          4
   *    /          /
   *   2   =>     2
   *  / \        / \
   * 3   1      1   1
   *           /     \
   *          3       1
   */
  root = CreateTreeNode("4 2 # 3 1"), v = 1, d = 3;
  got = sol.addOneRow(root, v, d);
  EXPECT_EQ(4, got->val);
  EXPECT_EQ(2, got->left->val);
  EXPECT_EQ(1, got->left->left->val);
  EXPECT_EQ(1, got->left->right->val);
  EXPECT_EQ(3, got->left->left->left->val);
  EXPECT_EQ(1, got->left->right->right->val);
  DeleteTreeNode(got);

  /**
   *      4                  1
   *    /   \               /
   *   2     6   =>        4
   *  / \   /            /   \
   * 3   1 5            2     6
   *                   / \   /
   *                  3   1 5
   */
  root = CreateTreeNode("4 2 6 3 1 5"), v = 1, d = 1;
  got = sol.addOneRow(root, v, d);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(4, got->left->val);
  EXPECT_EQ(2, got->left->left->val);
  EXPECT_EQ(6, got->left->right->val);
  EXPECT_EQ(3, got->left->left->left->val);
  EXPECT_EQ(1, got->left->left->right->val);
  EXPECT_EQ(5, got->left->right->left->val);
  DeleteTreeNode(got);

  exit(EXIT_SUCCESS);
}
