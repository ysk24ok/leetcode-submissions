#include <gtest/gtest.h>

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    dfs(root, 0);
    return root;
  }

  int dfs(TreeNode* node, int sum) {
    if (!node) { return sum; }
    int sum_right = sum;
    sum_right = dfs(node->right, sum);
    node->val += sum_right;
    int sum_all = node->val;
    sum_all = dfs(node->left, sum_all);
    return sum_all;
  }
};

int main() {
  Solution sol;
  TreeNode *root, *got;

  root = CreateTreeNode("4 1 6 0 2 5 7 # # # 3 # # # 8");
  got = sol.convertBST(root);
  EXPECT_EQ(30, got->val);
  EXPECT_EQ(36, got->left->val);
  EXPECT_EQ(21, got->right->val);
  EXPECT_EQ(36, got->left->left->val);
  EXPECT_EQ(35, got->left->right->val);
  EXPECT_EQ(26, got->right->left->val);
  EXPECT_EQ(15, got->right->right->val);
  EXPECT_EQ(33, got->left->right->right->val);
  EXPECT_EQ(8, got->right->right->right->val);
  DeleteTreeNode(root);

  root = CreateTreeNode("0 # 1");
  got = sol.convertBST(root);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(1, got->right->val);
  DeleteTreeNode(root);

  root = CreateTreeNode("1 0 2");
  got = sol.convertBST(root);
  EXPECT_EQ(3, got->val);
  EXPECT_EQ(3, got->left->val);
  EXPECT_EQ(2, got->right->val);
  DeleteTreeNode(root);

  root = CreateTreeNode("3 2 4 1");
  got = sol.convertBST(root);
  EXPECT_EQ(7, got->val);
  EXPECT_EQ(9, got->left->val);
  EXPECT_EQ(4, got->right->val);
  EXPECT_EQ(10, got->left->left->val);
  DeleteTreeNode(root);

  EXPECT_EQ(nullptr, sol.convertBST(nullptr));

  exit(EXIT_SUCCESS);
}
