#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode*> node_stack;
    while (root || !node_stack.empty()) {
      while (root) {
        node_stack.push(root);
        root = root->left;
      }
      root = node_stack.top();
      node_stack.pop();
      ret.push_back(root->val);
      root = root->right;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  vector<int> got, expected;

  root = CreateTreeNode("1 # 2 # # 3 ;");
  got = sol.inorderTraversal(root);
  expected = {1,3,2};
  assert(got == expected);
  DeleteTreeNode(root);

  //     1
  //   2   3
  //  4 5 6 7
  root = CreateTreeNode("1 2 3 4 5 6 7 ;");
  got = sol.inorderTraversal(root);
  expected = {4,2,5,1,6,3,7};
  assert(got == expected);
  DeleteTreeNode(root);

  got = sol.inorderTraversal(nullptr);
  assert(got.size() == 0);
}
