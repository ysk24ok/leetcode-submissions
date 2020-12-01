#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    int max_depth = 0;
    if (!root) { return max_depth; }
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
      pair<TreeNode*, int>& p = q.front();
      TreeNode* node = p.first;
      int depth = p.second;
      max_depth = max(depth, max_depth);
      q.pop();
      if (node->left) {
        q.push({node->left, depth + 1});
      }
      if (node->right) {
        q.push({node->right, depth + 1});
      }
    }
    return max_depth;
  }
};

int main() {
  Solution sol;
  string s;
  TreeNode* node;
  int expected;

  s = "3 9 20 # # 15 7";
  node = CreateTreeNode(s);
  expected = 3;
  EXPECT_EQ(expected, sol.maxDepth(node));
  DeleteTreeNode(node);

  node = new TreeNode(0);
  expected = 1;
  EXPECT_EQ(expected, sol.maxDepth(node));
  delete node;

  node = nullptr;
  expected = 0;
  EXPECT_EQ(expected, sol.maxDepth(node));

  exit(EXIT_SUCCESS);
}
