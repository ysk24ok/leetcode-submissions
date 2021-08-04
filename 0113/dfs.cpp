#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return {};
    }
    vector<vector<int>> paths;
    vector<int> path;
    dfs(root, paths, path, targetSum);
    return paths;
  }
  
  void dfs(TreeNode* node, vector<vector<int>>& paths, vector<int>& path, int remainingSum) {
    if (!node->left and !node->right) {
      if (remainingSum == node->val) {
        path.push_back(node->val);
        paths.push_back(path);
        path.pop_back();
      }
      return;
    }
    if (node->left) {
      path.push_back(node->val);
      dfs(node->left, paths, path, remainingSum - node->val);
      path.pop_back();
    }
    if (node->right) {
      path.push_back(node->val);
      dfs(node->right, paths, path, remainingSum - node->val);
      path.pop_back();
    }
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int targetSum;
  vector<vector<int>> expected;
  
  root = CreateTreeNode("5 4 8 11 # 13 4 7 2 # # 5 1");
  targetSum = 22;
  expected = {{5, 4, 11, 2}, {5, 8, 4, 5}};
  EXPECT_EQ(expected, sol.pathSum(root, targetSum));
  DeleteTreeNode(root);
  
  root = CreateTreeNode("1 2 3");
  targetSum = 5;
  expected = {};
  EXPECT_EQ(expected, sol.pathSum(root, targetSum));
  DeleteTreeNode(root);
  
  root = CreateTreeNode("1 2");
  targetSum = 0;
  expected = {};
  EXPECT_EQ(expected, sol.pathSum(root, targetSum));
  DeleteTreeNode(root);

  root = nullptr;
  targetSum = 1;
  expected = {};
  EXPECT_EQ(expected, sol.pathSum(root, targetSum));

  exit(EXIT_SUCCESS);
}
