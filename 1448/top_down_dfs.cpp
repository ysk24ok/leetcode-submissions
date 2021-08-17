#include <gtest/gtest.h>

#include <limits>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int goodNodes(TreeNode* root) {
    int ret = 0;
    dfs(root, numeric_limits<int>::min(), ret);
    return ret;
  }
  
  void dfs(TreeNode* node, int maximum, int& ret) {
    if (!node) {
      return;
    }
    int new_maximum = maximum;
    if (node->val >= maximum) {
      ret++;
      new_maximum = node->val;
    }
    dfs(node->left, new_maximum, ret);
    dfs(node->right, new_maximum, ret);
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int expected;

  root = CreateTreeNode("3 1 4 3 # 1 5"), expected = 4;
  EXPECT_EQ(expected, sol.goodNodes(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("1"), expected = 1;
  EXPECT_EQ(expected, sol.goodNodes(root));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
