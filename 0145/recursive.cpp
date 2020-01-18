#include <cassert>
#include <iostream>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    dfs(root, ret);
    return ret;
  }

  void dfs(TreeNode* node, vector<int>& ret) {
    if (!node) return;
    dfs(node->left, ret);
    dfs(node->right, ret);
    ret.push_back(node->val);
  }
};

int main() {
  Solution sol;
  string str;
  TreeNode* root;
  vector<int> got, expected;

  root = CreateTreeNode("1 # 2 # # 3 ;");
  expected = {3,2,1};
  got = sol.postorderTraversal(root);
  assert(got == expected);
  DeleteTreeNode(root);

  root = CreateTreeNode("1 2 3 4 5 6 7 ;");
  expected = {4,5,2,6,7,3,1};
  got = sol.postorderTraversal(root);
  assert(got == expected);
  DeleteTreeNode(root);

  got = sol.postorderTraversal(nullptr);
  assert(got.size() == 0);
}
