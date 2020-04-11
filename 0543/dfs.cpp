#include <algorithm>
#include <cassert>
#include <iostream>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int ret = 0;
    dfs(root, ret);
    return ret;
  }

  int dfs(TreeNode* node, int& ret) {
    if (!node) return 0;
    int left = dfs(node->left, ret);
    int right = dfs(node->right, ret);
    ret = max(ret, left + right);
    return max(left, right) + 1;
  }
};

int main() {
  Solution sol;
  TreeNode* root;

  root = CreateTreeNode("1 2 3 4 5 ;");
  assert(sol.diameterOfBinaryTree(root) == 3);
  DeleteTreeNode(root);

  root = CreateTreeNode("0 ;");
  assert(sol.diameterOfBinaryTree(root) == 0);
  DeleteTreeNode(root);
}
