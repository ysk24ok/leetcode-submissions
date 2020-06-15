#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) { return nullptr; }
    if (val < root->val) {
      return searchBST(root->left, val);
    } else if (val > root->val) {
      return searchBST(root->right, val);
    } else { return root; }
  }
};

int main() {
  Solution sol;
  int val;
  TreeNode* root = CreateTreeNode("4 2 7 1 3 ;");
  TreeNode* got;

  val = 2;
  got = sol.searchBST(root, val);
  EXPECT_EQ(2, got->val);

  val = 5;
  EXPECT_FALSE(sol.searchBST(root, val));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
