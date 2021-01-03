#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    TreeNode* ret = nullptr;
    queue<pair<TreeNode*, TreeNode*>> q;
    q.push({original, cloned});
    while (!q.empty()) {
      pair<TreeNode*, TreeNode*> elem = q.front();
      q.pop();
      TreeNode* original = elem.first;
      TreeNode* cloned = elem.second;
      if (!original) { continue; }
      if (original == target) {
        ret = cloned;
        break;
      }
      q.push({original->left, cloned->left});
      q.push({original->right, cloned->right});
    }
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