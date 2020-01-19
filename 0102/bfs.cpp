#include <cassert>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    if (!root) return ret;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    pair<TreeNode*, int> node_pair;
    TreeNode* node;
    int level;
    while (!q.empty()){
      node_pair = q.front();
      q.pop();
      node = node_pair.first;
      level = node_pair.second;
      if (ret.size() <= level) ret.resize(level+1);
      ret[level].push_back(node->val);
      if (node->left) q.push({node->left, level+1});
      if (node->right) q.push({node->right, level+1});
    }
    return ret;
  }
};

int main() {
  Solution sol;
  TreeNode* node;
  vector<vector<int>> got;
  vector<int> expected;

  node = CreateTreeNode("3 9 20 # # 15 7 ;");
  got = sol.levelOrder(node);
  expected = {3};
  assert (got[0] == expected);
  expected = {9,20};
  assert (got[1] == expected);
  expected = {15,7};
  assert (got[2] == expected);
  DeleteTreeNode(node);

  node = CreateTreeNode("1 2 3 4 5 6 7 ;");
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
