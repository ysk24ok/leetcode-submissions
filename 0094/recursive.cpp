#include <cassert>
#include <iostream>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    dfs(root, ret);
    return ret;
  }

  void dfs(TreeNode* node, vector<int>& ret) {
    if (!node) return;
    dfs(node->left, ret);
    ret.push_back(node->val);
    dfs(node->right, ret);
  }
};

int main() {
  Solution sol;
  string str;
  TreeNode* root;
  vector<int> got, expected;

  root = CreateTreeNode("1 # 2 # # 3 ;");
  expected = {1,3,2};
  got = sol.inorderTraversal(root);
  assert(got == expected);
  DeleteTreeNode(root);

  root = CreateTreeNode("1 2 3 4 5 6 7 ;");
  expected = {4,2,5,1,6,3,7};
  got = sol.inorderTraversal(root);
  assert(got == expected);
  DeleteTreeNode(root);

  got = sol.inorderTraversal(nullptr);
  assert(got.size() == 0);
}
