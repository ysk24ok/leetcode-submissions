#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int maxAncestorDiff(TreeNode* root) {
    int ret = 0;
    dfs(root->left, root->val, root->val, ret);
    dfs(root->right, root->val, root->val, ret);
    return ret;
  }

  void dfs(TreeNode* node, int minval, int maxval, int& ret) {
    if (!node) { return; }
    ret = max({ret, abs(minval - node->val), abs(maxval - node->val)});
    minval = min(node->val, minval);
    maxval = max(node->val, maxval);
    dfs(node->left, minval, maxval, ret);
    dfs(node->right, minval, maxval, ret);
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int expected;

  /**
   *       8
   *      / \
   *     3   10
   *    / \    \
   *   1   6    14
   *      / \     \
   *     4   7     13
   */
  root = CreateTreeNode("8 3 10 1 6 # 14 # # 4 7 13");
  expected = 7;
  EXPECT_EQ(expected, sol.maxAncestorDiff(root));
  DeleteTreeNode(root);

  /**
   *  1
   *   \
   *    2
   *     \
   *      0
   *     /
   *    3
   */
  root = CreateTreeNode("1 # 2 # 0 3");
  expected = 3;
  EXPECT_EQ(expected, sol.maxAncestorDiff(root));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
