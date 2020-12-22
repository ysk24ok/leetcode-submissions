#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    return dfs(root) != -1;
  }

  int dfs(TreeNode* node) {
    if (!node) { return 0; }
    int left_height = dfs(node->left);
    int right_height = dfs(node->right);
    if (left_height == -1 || right_height == -1) { return -1; }
    if (abs(left_height - right_height) <= 1) {
      return max(left_height, right_height) + 1;
    } else { return -1; }
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  bool expected;

  root = CreateTreeNode("3 9 20 # # 15 7"), expected = true;
  EXPECT_EQ(expected, sol.isBalanced(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("1 2 2 3 3 # # 4 4"), expected = false;
  EXPECT_EQ(expected, sol.isBalanced(root));
  DeleteTreeNode(root);

  root = nullptr, expected = true;
  EXPECT_EQ(expected, sol.isBalanced(root));

  exit(EXIT_SUCCESS);
}
