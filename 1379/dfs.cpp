#include <gtest/gtest.h>

#include <cstdlib>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if (!original) { return nullptr; }
    if (original == target) { return cloned; }
    TreeNode* ret = nullptr;
    ret = getTargetCopy(original->left, cloned->left, target);
    if (ret) { return ret; }
    ret = getTargetCopy(original->right, cloned->right, target);
    return ret;
  }
};

int main() {
  Solution sol;
  string nodes;
  TreeNode *original, *cloned, *target, *expected;

  nodes = "7 4 3 # # 6 19";
  original = CreateTreeNode(nodes);
  cloned = CreateTreeNode(nodes);
  target = original->right;
  expected = cloned->right;
  EXPECT_EQ(expected, sol.getTargetCopy(original, cloned, target));
  DeleteTreeNode(original);
  DeleteTreeNode(cloned);

  nodes = "7";
  original = CreateTreeNode(nodes);
  cloned = CreateTreeNode(nodes);
  target = original;
  expected = cloned;
  EXPECT_EQ(expected, sol.getTargetCopy(original, cloned, target));
  DeleteTreeNode(original);
  DeleteTreeNode(cloned);

  nodes = "8 # 6 # 5 # 4 # 3 # 2 # 1";
  original = CreateTreeNode(nodes);
  cloned = CreateTreeNode(nodes);
  target = original->right->right->right;
  expected = cloned->right->right->right;
  EXPECT_EQ(expected, sol.getTargetCopy(original, cloned, target));
  DeleteTreeNode(original);
  DeleteTreeNode(cloned);

  nodes = "1 2 3 4 5 6 7 8 9 10";
  original = CreateTreeNode(nodes);
  cloned = CreateTreeNode(nodes);
  target = original->left->right;
  expected = cloned->left->right;
  EXPECT_EQ(expected, sol.getTargetCopy(original, cloned, target));
  DeleteTreeNode(original);
  DeleteTreeNode(cloned);

  nodes = "1 2 # 3";
  original = CreateTreeNode(nodes);
  cloned = CreateTreeNode(nodes);
  target = original->left;
  expected = cloned->left;
  EXPECT_EQ(expected, sol.getTargetCopy(original, cloned, target));
  DeleteTreeNode(original);
  DeleteTreeNode(cloned);

  exit(EXIT_SUCCESS);
}
