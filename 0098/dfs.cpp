#include <gtest/gtest.h>

#include <cstdlib>
#include <numeric>
#include <string>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

// used implmentation in https://leetcode.com/problems/validate-binary-search-tree/discuss/32141/C%2B%2B-simple-recursive-solution
// No need to use buggy INT_MIN and INT_MAX
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return dfs(root, nullptr, nullptr);
  }

  bool dfs(TreeNode* node, TreeNode* min_node, TreeNode* max_node) {
    if (!node) { return true; }
    if (min_node && node->val <= min_node->val) { return false; }
    if (max_node && max_node->val <= node->val) { return false; }
    if (!dfs(node->left, min_node, node)) { return false; }
    if (!dfs(node->right, node, max_node)) { return false; }
    return true;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  bool expected;

  root = CreateTreeNode("2 1 3");
  expected = true;
  EXPECT_EQ(expected, sol.isValidBST(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("5 1 4 # # 3 6");
  expected = false;
  EXPECT_EQ(expected, sol.isValidBST(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("1 1");
  expected = false;
  EXPECT_EQ(expected, sol.isValidBST(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("2147483647");
  expected = true;
  EXPECT_EQ(expected, sol.isValidBST(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("-2147483648 -2147483648");
  expected = false;
  EXPECT_EQ(expected, sol.isValidBST(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("-2147483648 # 2147483647");
  expected = true;
  EXPECT_EQ(expected, sol.isValidBST(root));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
