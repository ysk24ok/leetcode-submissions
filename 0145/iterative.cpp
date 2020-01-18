#include <algorithm>
#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    if (!root) return ret;
    stack<TreeNode*> node_stack;
    node_stack.push(root);
    TreeNode* node;
    while (!node_stack.empty()) {
      node = node_stack.top();
      node_stack.pop();
      ret.push_back(node->val);
      if (node->left) node_stack.push(node->left);
      if (node->right) node_stack.push(node->right);
    }
    reverse(ret.begin(), ret.end());
    return ret;
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

  //    1
  //  2   3
  // 4 5 6 7
  root = CreateTreeNode("1 2 3 4 5 6 7 ;");
  expected = {4,5,2,6,7,3,1};
  got = sol.postorderTraversal(root);
  assert(got == expected);
  DeleteTreeNode(root);

  got = sol.postorderTraversal(nullptr);
  assert(got.size() == 0);
}
