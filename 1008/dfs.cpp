#include <gtest/gtest.h>

#include <numeric>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    size_t i = 0;
    return dfs(preorder, i);
  }

  TreeNode* dfs(const vector<int>& preorder, size_t& i, int bound = numeric_limits<int>::max()) {
    if (i >= preorder.size() || preorder[i] > bound) { return nullptr; }
    TreeNode* node = new TreeNode(preorder[i]);
    i++;
    node->left = dfs(preorder, i, node->val);
    node->right = dfs(preorder, i, bound);
    return node;
  }
};

int main() {
  Solution sol;
  vector<int> preorder;
  TreeNode* got;

  preorder = {8,5,1,7,10,12};
  got = sol.bstFromPreorder(preorder);
  EXPECT_EQ(8, got->val);
  EXPECT_EQ(5, got->left->val);
  EXPECT_EQ(1, got->left->left->val);
  EXPECT_EQ(7, got->left->right->val);
  EXPECT_EQ(10, got->right->val);
  EXPECT_EQ(12, got->right->right->val);
  DeleteTreeNode(got);

  preorder = {};
  EXPECT_EQ(true, !sol.bstFromPreorder(preorder));
}
