#include <cassert>
#include <iostream>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    dfs(root, ret);
    return ret;
  }

  void dfs(TreeNode* node, vector<int>& ret) {
    if (!node) return;
    ret.push_back(node->val);
    dfs(node->left, ret);
    dfs(node->right, ret);
  }
};

int main() {
  Solution sol;
  string str;
  TreeNode* root;
  vector<int> got, expected;

  str = "1 # 2 # # 3 ;";
  root = CreateTreeNode(str);
  expected = {1,2,3};
  got = sol.preorderTraversal(root);
  assert(got == expected);
  DeleteTreeNode(root);

  got = sol.preorderTraversal(nullptr);
  assert(got.size() == 0);
}
