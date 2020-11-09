#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int findTilt(TreeNode* root) {
    int ret = 0;
    dfs(root, ret);
    return ret;
  }

  int dfs(TreeNode* node, int& ret) {
    if (!node) { return 0; }
    int left = dfs(node->left, ret);
    int right = dfs(node->right, ret);
    ret += abs(left - right);
    return left + right + node->val;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int expected;

  root = CreateTreeNode("1 2 3");
  expected = 1;
  EXPECT_EQ(expected, sol.findTilt(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("4 2 9 3 5 # 7");
  expected = 15;
  EXPECT_EQ(expected, sol.findTilt(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("21 7 14 1 1 2 2 3 3");
  expected = 9;
  EXPECT_EQ(expected, sol.findTilt(root));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
