#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  Solution() : ret(nullptr), max_height(0) {}

  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    ret = nullptr;
    max_height = 0;
    recursive(root, 1);
    return ret;
  }

  size_t recursive(TreeNode* node, size_t curr_height_from_top) {
    if (!node) { return 0; }
    size_t left_max_height_from_bottom = recursive(node->left, curr_height_from_top + 1);
    size_t right_max_height_from_bottom = recursive(node->right, curr_height_from_top + 1);
    size_t curr_max_height_from_bottom = max(left_max_height_from_bottom, right_max_height_from_bottom);
    size_t height = curr_height_from_top + curr_max_height_from_bottom + 1;
    if (left_max_height_from_bottom == right_max_height_from_bottom && height >= max_height) {
      max_height = height;
      ret = node;
    }
    return curr_max_height_from_bottom + 1;
  }

 private:
  TreeNode* ret;
  size_t max_height;
};

int main() {
  Solution sol;
  TreeNode *root, *got;

  //       3
  //     /   \
  //    5     1
  //   / \   / \
  //  6   2 0   8
  //     / \
  //    7   4
  root = CreateTreeNode("3 5 1 6 2 0 8 # # 7 4");
  got = sol.subtreeWithAllDeepest(root);
  EXPECT_EQ(2, got->val);
  EXPECT_EQ(7, got->left->val);
  EXPECT_EQ(nullptr, got->left->left);
  EXPECT_EQ(nullptr, got->left->right);
  EXPECT_EQ(4, got->right->val);
  EXPECT_EQ(nullptr, got->right->left);
  EXPECT_EQ(nullptr, got->right->right);
  DeleteTreeNode(root);

  root = CreateTreeNode("1");
  got = sol.subtreeWithAllDeepest(root);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(nullptr, got->left);
  EXPECT_EQ(nullptr, got->right);
  DeleteTreeNode(root);

  //   0
  //  / \
  // 1   3
  //  \
  //   2
  root = CreateTreeNode("0 1 3 # 2");
  got = sol.subtreeWithAllDeepest(root);
  EXPECT_EQ(2, got->val);
  EXPECT_EQ(nullptr, got->left);
  EXPECT_EQ(nullptr, got->right);
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
