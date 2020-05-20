#include <cstdlib>
#include <stack>

#include "gtest/gtest.h"

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> s;
    int ret = 0;
    int count = 0;
    s.push(root);
    root = root->left;
    while (true) {
      while (root) {
        s.push(root);
        root = root->left;
      }
      root = s.top();
      s.pop();
      if (++count == k) {
        ret = root->val;
        break;
      }
      root = root->right;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  TreeNode* node;
  int k, expected;

  //   3
  //  / \
  // 1   4
  //  \
  //   2
  node = CreateTreeNode("3 1 4 # 2 ;");
  k = 1, expected = 1;
  EXPECT_EQ(expected, sol.kthSmallest(node, k));
  DeleteTreeNode(node);

  //       5
  //      / \
  //     3   6
  //    / \
  //   2   4
  //  /
  // 1
  node = CreateTreeNode("5 3 6 2 4 # # 1 ;");
  k = 3, expected = 3;
  EXPECT_EQ(expected, sol.kthSmallest(node, k));
  DeleteTreeNode(node);

  //        10
  //      /    \
  //     4      12
  //    / \    /  \
  //   2   6  11  13
  //  / \ / \
  // 1  3 5  7
  node = CreateTreeNode("10 4 12 2 6 11 13 1 3 5 7 ;");
  k = 9, expected = 11;
  EXPECT_EQ(expected, sol.kthSmallest(node, k));
  DeleteTreeNode(node);

  exit(EXIT_SUCCESS);
}
