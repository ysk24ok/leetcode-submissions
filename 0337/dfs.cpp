#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int rob(TreeNode* root) {
    pair<int, int> ret = dfs(root);
    return max(ret.first, ret.second);
  }

  // ret.first is the max money the thief can get
  //  when the node is selected
  // ret.second is the max money the thief can get
  //  when the node is not selected
  pair<int, int> dfs(TreeNode* node) {
    if (!node) return {0, 0};
    pair<int, int> left = dfs(node->left);
    pair<int, int> right = dfs(node->right);
    pair<int, int> ret;
    ret.first = node->val + left.second + right.second;
    ret.second = max({
      left.first + right.first,
      left.second + right.second,
      left.first + right.second,
      left.second + right.first
    });
    return ret;
  }
};

int main() {
  Solution sol;
  std::string s;
  TreeNode* node;
  int got;


  //   3
  //  / \
  // 2   3
  //  \   \
  //   3   1
  s = "3 2 3 # 3 # 1";
  node = CreateTreeNode(s);
  assert(sol.rob(node) == 7);

  //     3
  //    / \
  //   4   5
  //  / \   \
  // 1   3   1
  s = "3 4 5 1 3 # 1";
  node = CreateTreeNode(s);
  assert(sol.rob(node) == 9);

  //        2
  // (1,4) / \ (3,0)
  //      1   3
  //       \ (4,0)
  //        4
  s = "2 1 3 # 4";
  node = CreateTreeNode(s);
  assert(sol.rob(node) == 7);

  //       5
  //      / \
  //     1   1
  //    /     \
  //   1       5
  //  /       / \
  // 9       3   3
}
