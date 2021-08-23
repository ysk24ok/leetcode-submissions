#include <gtest/gtest.h>

#include <stack>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    stack<TreeNode*> stack_left;
    stack<TreeNode*> stack_right;
    addNodeToStack(root, stack_left, false);  // Get the smallest node
    addNodeToStack(root, stack_right, true);  // Get the largest node
    while (stack_left.top() != stack_right.top()) {
      int sum = stack_left.top()->val + stack_right.top()->val;
      if (sum < k) {
        // Get the second smallest node
        TreeNode* node = stack_left.top();
        stack_left.pop();
        addNodeToStack(node->right, stack_left, false);
      } else if (sum > k) {
        // Get the second largest node
        TreeNode* node = stack_right.top();
        stack_right.pop();
        addNodeToStack(node->left, stack_right, true);
      } else {
        return true;
      }
    }
    return false;
  }

 private:
  void addNodeToStack(TreeNode* node, stack<TreeNode*>& s, bool larger) {
    while (node) {
      s.push(node);
      node = larger ? node->right : node->left;
    }
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  int k;
  bool expected;

  root = CreateTreeNode("5 3 6 2 4 # 7"), k = 9, expected = true;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  root = CreateTreeNode("5 3 6 2 4 # 7"), k = 28, expected = false;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  root = CreateTreeNode("2 1 3"), k = 4, expected = true;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  root = CreateTreeNode("2 1 3"), k = 1, expected = false;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  root = CreateTreeNode("2 1 3"), k = 3, expected = true;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  /**
   *      0
   *     / \
   *   -1   2
   *   /     \
   *  -3      4
   */
  root = CreateTreeNode("0 -1 2 -3 # # 4"), k = -4, expected = true;
  EXPECT_EQ(expected, sol.findTarget(root, k));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
