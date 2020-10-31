#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    first_ = nullptr;
    second_ = nullptr;
    prev_ = nullptr;
    traverse(root);
    swap();
  }

  void traverse(TreeNode* node) {
    if (!node) { return; }
    traverse(node->left);
    if (prev_) {
      if (!first_ && prev_->val > node->val) {
        first_ = prev_;
      }
      if (first_ && prev_->val > node->val) {
        second_ = node;
      }
    }
    prev_ = node;
    traverse(node->right);
  }

  void swap() {
    int tmp = first_->val;
    first_->val = second_->val;
    second_->val = tmp;
  }

 private:
  TreeNode* first_;
  TreeNode* second_;
  TreeNode* prev_;
};

int main() {
  Solution sol;
  TreeNode* root;

  root = CreateTreeNode("1 3 # # 2");
  sol.recoverTree(root);
  EXPECT_EQ(3, root->val);
  EXPECT_EQ(1, root->left->val);
  EXPECT_EQ(2, root->left->right->val);
  DeleteTreeNode(root);

  /*      3
   *     / \
   *    1   4
   *       /
   *      2
   */
  root = CreateTreeNode("3 1 4 # # 2");
  sol.recoverTree(root);
  EXPECT_EQ(2, root->val);
  EXPECT_EQ(1, root->left->val);
  EXPECT_EQ(4, root->right->val);
  EXPECT_EQ(3, root->right->left->val);
  DeleteTreeNode(root);

  /*      2
   *     / \
   *    3   4
   *       /
   *      1
   *  -> 3 2 1 4
   */
  root = CreateTreeNode("2 3 4 # # 1");
  sol.recoverTree(root);
  EXPECT_EQ(2, root->val);
  EXPECT_EQ(1, root->left->val);
  EXPECT_EQ(4, root->right->val);
  EXPECT_EQ(3, root->right->left->val);
  DeleteTreeNode(root);

  /*      4
   *     / \
   *    1   2
   *       /
   *      3
   */
  root = CreateTreeNode("4 1 2 # # 3");
  sol.recoverTree(root);
  EXPECT_EQ(2, root->val);
  EXPECT_EQ(1, root->left->val);
  EXPECT_EQ(4, root->right->val);
  EXPECT_EQ(3, root->right->left->val);
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
