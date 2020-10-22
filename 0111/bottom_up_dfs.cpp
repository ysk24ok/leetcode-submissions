#include <gtest/gtest.h>

#include <cstdlib>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int minDepth(TreeNode* root) {
    return dfs(root);
  }

  int dfs(TreeNode* node) {
    if (!node) { return 0; }
    int left_depth = dfs(node->left);
    int right_depth = dfs(node->right);
    if (left_depth == 0) {
      return right_depth + 1;
    } else if (right_depth == 0) {
      return left_depth + 1;
    } else {
      return min(left_depth, right_depth) + 1;
    }
  }
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

  exit(EXIT_SUCCESS);
}
