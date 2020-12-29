#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_set>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int pseudoPalindromicPaths (TreeNode* root) {
    int ret = 0;
    unordered_set<int> set;
    top_down_dfs(root, set, ret);
    return ret;
  }

  void top_down_dfs(TreeNode* node, unordered_set<int>& set, int& ret) {
    if (!node) { return; }
    if (set.find(node->val) == set.end()) {
      set.insert(node->val);
    } else {
      set.erase(node->val);
    }
    if (!node->left && !node->right && set.size() <= 1) {
      ret++;
    }
    top_down_dfs(node->left, set, ret);
    top_down_dfs(node->right, set, ret);
    if (set.find(node->val) == set.end()) {
      set.insert(node->val);
    } else {
      set.erase(node->val);
    }
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int expected;

  root = CreateTreeNode("2 3 1 3 1 # 1"), expected = 2;
  EXPECT_EQ(expected, sol.pseudoPalindromicPaths(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("2 1 1 1 3 # # # # # 1"), expected = 1;
  EXPECT_EQ(expected, sol.pseudoPalindromicPaths(root));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
