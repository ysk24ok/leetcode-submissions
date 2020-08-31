#include <cassert>
#include <stack>
#include <string>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    if (!root) return ret;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* node;
    while (!s.empty()) {
      node = s.top();
      s.pop();
      if (!node) continue;
      ret.push_back(node->val);
      s.push(node->right);
      s.push(node->left);
    }
    return ret;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  vector<int> got, expected;

  root = CreateTreeNode("1 # 2 3");
  got = sol.preorderTraversal(root);
  expected = {1,2,3};
  assert(got == expected);
  DeleteTreeNode(root);

  root = CreateTreeNode("1 2 3 4 5 6 7");
  got = sol.preorderTraversal(root);
  expected = {1,2,4,5,3,6,7};
  assert(got == expected);
  DeleteTreeNode(root);

  got = sol.preorderTraversal(nullptr);
  assert(got.size() == 0);
}
