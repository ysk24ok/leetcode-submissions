#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>

#include "leetcode/assert.hpp"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int ret = numeric_limits<int>::min();
    return max(ret, dfs(root, ret));
  }

  int dfs(TreeNode* node, int& ret) {
    if (!node->left && !node->right) {
      return node->val;
    } else if (!node->left && node->right) {
      int rval = dfs(node->right, ret);
      ret = max(ret, rval);
      return max(node->val, node->val + rval);
    } else if (node->left && !node->right) {
      int lval = dfs(node->left, ret);
      ret = max(ret, lval);
      return max(node->val, node->val + lval);
    } else {
      int lval = dfs(node->left, ret);
      int rval = dfs(node->right, ret);
      ret = max({ret, lval + node->val + rval, lval, rval});
      return max({node->val, node->val + lval, node->val + rval});
    }
  }
};

int main() {
  Solution sol;
  TreeNode* node = nullptr;

  node = CreateTreeNode("1 2 3 ;");
  ExpectEqual(6, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("1 -2 -3 ;");
  ExpectEqual(1, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("1 -2 3 ;");
  ExpectEqual(4, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("-10 9 20 # # 15 7 ;");
  ExpectEqual(42, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("10 9 20 # # 15 7 ;");
  ExpectEqual(54, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("-10 9 20 # # 15 -7 ;");
  ExpectEqual(35, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("-10 -9 20 # # -15 -7 ;");
  ExpectEqual(20, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("-3 ;");
  ExpectEqual(-3, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("-3 1 ;");
  ExpectEqual(1, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("-3 # 1 ;");
  ExpectEqual(1, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("2 -1 ;");
  ExpectEqual(2, sol.maxPathSum(node));
  DeleteTreeNode(node);

  node = CreateTreeNode("2 # -1 ;");
  ExpectEqual(2, sol.maxPathSum(node));
  DeleteTreeNode(node);
}
