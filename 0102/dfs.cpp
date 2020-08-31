#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    dfs(root, ret, 0);
    return ret;
  }

  void dfs(TreeNode* node, vector<vector<int>>& ret, int level) {
    if (!node) return;
    if (level >= ret.size()) ret.resize(level+1);
    ret[level].push_back(node->val);
    dfs(node->left, ret, level+1);
    dfs(node->right, ret, level+1);
  }
};

int main() {
  Solution sol;
  TreeNode* node;
  vector<vector<int>> got;
  vector<int> expected;

  node = CreateTreeNode("3 9 20 # # 15 7");
  got = sol.levelOrder(node);
  expected = {3};
  assert (got[0] == expected);
  expected = {9,20};
  assert (got[1] == expected);
  expected = {15,7};
  assert (got[2] == expected);
  DeleteTreeNode(node);

  node = CreateTreeNode("1 2 3 4 5 6 7");
  got = sol.levelOrder(node);
  expected = {1};
  assert (got[0] == expected);
  expected = {2,3};
  assert (got[1] == expected);
  expected = {4,5,6,7};
  assert (got[2] == expected);
  DeleteTreeNode(node);

  got = sol.levelOrder(nullptr);
  assert(got.size() == 0);
}
