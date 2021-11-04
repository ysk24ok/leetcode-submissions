#include <gtest/gtest.h>

#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    return dfs(root, false);
  }

  int dfs(TreeNode* root, bool is_left) {
    if (!root) {
      return 0;
    }
    if (!root->left && !root->right && is_left) {
      return root->val;
    }
    int ret = dfs(root->left, true);
    ret += dfs(root->right, false);
    return ret;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int expected;

  root = CreateTreeNode("3 9 20 # # 15 7"), expected = 24;
  EXPECT_EQ(expected, sol.sumOfLeftLeaves(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("1"), expected = 0;
  EXPECT_EQ(expected, sol.sumOfLeftLeaves(root));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
