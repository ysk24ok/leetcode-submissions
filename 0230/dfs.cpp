#include <cassert>
#include <iostream>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    int ret = 0;
    dfs(root, k, 0, ret);
    return ret;
  }

  int dfs(TreeNode* node, int k, int offset, int& ret) {
    if (!node) return 0;
    int left = dfs(node->left, k, offset, ret);
    int id = offset + left + 1;
    int right = dfs(node->right, k, id, ret);
    if (id == k) {
      ret = node->val;
    }
    return left + right + 1;
  }
};

int main() {
  Solution sol;
  TreeNode* node;

  //   3
  //  / \
  // 1   4
  //  \
  //   2
  node = CreateTreeNode("3 1 4 # 2");
  assert(sol.kthSmallest(node, 1) == 1);
  DeleteTreeNode(node);

  //       5
  //      / \
  //     3   6
  //    / \
  //   2   4
  //  /
  // 1
  node = CreateTreeNode("5 3 6 2 4 # # 1");
  assert(sol.kthSmallest(node, 3) == 3);
  DeleteTreeNode(node);

  //        10
  //      /    \
  //     4      12
  //    / \    /  \
  //   2   6  11  13
  //  / \ / \
  // 1  3 5  7
  node = CreateTreeNode("10 4 12 2 6 11 13 1 3 5 7");
  assert(sol.kthSmallest(node, 9) == 11);
  DeleteTreeNode(node);
}
