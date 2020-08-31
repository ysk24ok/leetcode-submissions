#include <cassert>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    vector<int> nums;
    dfs(root, "", nums);
    return accumulate(nums.begin(), nums.end(), 0);
  }

  void dfs(TreeNode* node, const string& val, vector<int>& nums) {
    if (!node) { return; }
    string new_val = val + to_string(node->val);
    if (!node->left && !node->right) {
      nums.push_back(stoi(new_val));
    }
    dfs(node->left, new_val, nums);
    dfs(node->right, new_val, nums);
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int expected;

  root = CreateTreeNode("1 2 3");
  expected = 25;
  EXPECT_EQ(expected, sol.sumNumbers(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("4 9 0 5 1");
  expected = 1026;
  EXPECT_EQ(expected, sol.sumNumbers(root));
  DeleteTreeNode(root);

  root = nullptr;
  expected = 0;
  EXPECT_EQ(expected, sol.sumNumbers(root));

  exit(EXIT_SUCCESS);
}
