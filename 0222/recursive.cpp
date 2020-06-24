#include <cmath>
#include <cstdlib>

#include "gtest/gtest.h"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (!root) { return 0; }
    return recursion(root);
  }

  int recursion(TreeNode* node) {
    if (!node) { return 0; }
    int left_height = height(node->left);
    int right_height = height(node->right);
    // the left subtree and the right subtree have the same height
    //         1
    //      2     3
    //     4 5   6
    if (left_height == right_height) {
      int left_nodes = pow(2, left_height) - 1;
      return 1 + left_nodes + recursion(node->right);
    //         1
    //      2     3
    //     4
    } else {
      int right_nodes = pow(2, right_height) - 1;
      return 1 + right_nodes + recursion(node->left);
    }
  }

  int height(TreeNode* node) {
    if (!node) { return 0; }
    return 1 + height(node->left);
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int expected;

  //      1
  //    2   3
  //   4 5 6
  root = CreateTreeNode("1 2 3 4 5 6 ;");
  expected = 6;
  EXPECT_EQ(expected, sol.countNodes(root));
  DeleteTreeNode(root);

  //      1
  //    2   3
  //   4 5
  root = CreateTreeNode("1 2 3 4 5 ;");
  expected = 5;
  EXPECT_EQ(expected, sol.countNodes(root));
  DeleteTreeNode(root);

  //      1
  //    2   3
  //   4 5 6 7
  root = CreateTreeNode("1 2 3 4 5 6 7 ;");
  expected = 7;
  EXPECT_EQ(expected, sol.countNodes(root));
  DeleteTreeNode(root);

  //      1
  //    2   3
  //   4
  root = CreateTreeNode("1 2 3 4 ;");
  expected = 4;
  EXPECT_EQ(expected, sol.countNodes(root));
  DeleteTreeNode(root);

  expected = 0;
  EXPECT_EQ(expected, sol.countNodes(nullptr));

  exit(EXIT_SUCCESS);
}
