#include <gtest/gtest.h>

#include <cstdlib>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) { return 0; }
    min_depth_ = numeric_limits<int>::max();
    dfs(root, 0);
    return min_depth_;
  }

  void dfs(TreeNode* node, int depth) {
    if (!node->left && !node->right) {
      min_depth_ = min(min_depth_, depth + 1);
      return;
    }
    if (node->left) {
      dfs(node->left, depth + 1);
    }
    if (node->right) {
      dfs(node->right, depth + 1);
    }
  }

 private:
  int min_depth_;
};

int main() {
  Solution sol;
  TreeNode* root;
  int expected;

  //    3
  //   / \
  //  9   20
  //     /  \
  //    15   7
  root = CreateTreeNode("3 9 20 # # 15 7");
  expected = 2;
  EXPECT_EQ(expected, sol.minDepth(root));
  DeleteTreeNode(root);

  //   2
  //    \
  //     3
  //      \
  //       4
  //        \
  //         5
  //          \
  //           6
  root = CreateTreeNode("2 # 3 # 4 # 5 # 6");
  expected = 5;
  EXPECT_EQ(expected, sol.minDepth(root));
  DeleteTreeNode(root);

  root = nullptr;
  expected = 0;
  EXPECT_EQ(expected, sol.minDepth(root));

  exit(EXIT_SUCCESS);
}
