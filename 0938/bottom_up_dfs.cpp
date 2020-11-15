#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    return dfs(root, low, high);
  }

  int dfs(TreeNode* node, int low, int high) {
    if (!node) { return 0; }
    int sum = 0;
    if (low <= node->val && node->val <= high) {
      sum += node->val;
    }
    if (low < node->val) {
      sum += dfs(node->left, low, high);
    }
    if (node->val < high) {
      sum += dfs(node->right, low, high);
    }
    return sum;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int low, high;
  int expected;

  root = CreateTreeNode("10 5 15 3 7 # 18");
  low = 7, high = 15;
  expected = 32;
  EXPECT_EQ(expected, sol.rangeSumBST(root, low, high));
  DeleteTreeNode(root);

  root = CreateTreeNode("10 5 15 3 7 13 18 1 # 6");
  low = 6, high = 10;
  expected = 23;
  EXPECT_EQ(expected, sol.rangeSumBST(root, low, high));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
