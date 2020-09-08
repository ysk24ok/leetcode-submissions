#include <gtest/gtest.h>

#include <queue>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int sumRootToLeaf(TreeNode* root) {
    int ret = 0;
    if (!root) { return ret; }
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      pair<TreeNode*, int> p = q.front();
      TreeNode* node = p.first;
      int val = p.second;
      q.pop();
      val <<= 1;
      val += node->val;
      if (!node->left && !node->right) {
        ret += val;
      }
      if (node->right) {
        q.push({node->right, val});
      }
      if (node->left) {
        q.push({node->left, val});
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int expected;

  root = CreateTreeNode("1 0 1 0 1 0 1");
  expected = 22;
  EXPECT_EQ(expected, sol.sumRootToLeaf(root));
  DeleteTreeNode(root);

  expected = 0;
  EXPECT_EQ(expected, sol.sumRootToLeaf(nullptr));

  exit(EXIT_SUCCESS);
}
