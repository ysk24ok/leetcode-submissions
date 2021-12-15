#include <gtest/gtest.h>

#include <vector>

#include <leetcode/tree.hpp>

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    return recursion(1, n);
  }

  vector<TreeNode*> recursion(int left, int right) {
    vector<TreeNode*> nodes;
    if (left == right) {
      nodes.push_back(new TreeNode(left));
      return nodes;
    } else if (left > right) {
      return nodes;
    }
    for (int root = left; root <= right; ++root) {
      vector<TreeNode*> left_subtree = recursion(left, root - 1);
      vector<TreeNode*> right_subtree = recursion(root + 1, right);
      if (left_subtree.size() == 0) {
        for (TreeNode* right_root : right_subtree) {
          TreeNode* root_node = new TreeNode(root);
          root_node->right = right_root;
          nodes.push_back(root_node);
        }
      } else if (right_subtree.size() == 0) {
        for (TreeNode* left_root : left_subtree) {
          TreeNode* root_node = new TreeNode(root);
          root_node->left = left_root;
          nodes.push_back(root_node);
        }
      } else {
        for (TreeNode* left_root : left_subtree) {
          for (TreeNode* right_root : right_subtree) {
            TreeNode* root_node = new TreeNode(root);
            root_node->left = left_root;
            root_node->right = right_root;
            nodes.push_back(root_node);
          }
        }
      }
    }
    return nodes;
  }
};

int main() {
  Solution sol;
  int n;
  vector<TreeNode*> actual;

  n = 1;
  actual = sol.generateTrees(n);
  EXPECT_EQ(actual.size(), 1);
  EXPECT_EQ(actual[0]->val, 1);
  EXPECT_FALSE(actual[0]->left);
  EXPECT_FALSE(actual[0]->right);
  for (TreeNode* node : actual) {
    DeleteTreeNode(node);
  }

  n = 2;
  actual = sol.generateTrees(n);
  EXPECT_EQ(actual.size(), 2);
  {
    EXPECT_EQ(actual[0]->val, 1);
    EXPECT_FALSE(actual[0]->left);
    EXPECT_EQ(actual[0]->right->val, 2);
    EXPECT_FALSE(actual[0]->right->left);
    EXPECT_FALSE(actual[0]->right->right);
  }
  {
    EXPECT_EQ(actual[1]->val, 2);
    EXPECT_EQ(actual[1]->left->val, 1);
    EXPECT_FALSE(actual[1]->right);
    EXPECT_FALSE(actual[1]->left->left);
    EXPECT_FALSE(actual[1]->left->right);
  }
  for (TreeNode* node : actual) {
    DeleteTreeNode(node);
  }

  n = 3;
  actual = sol.generateTrees(n);
  EXPECT_EQ(actual.size(), 5);
  {
    EXPECT_EQ(actual[0]->val, 1);
    EXPECT_EQ(actual[0]->right->val, 2);
    EXPECT_EQ(actual[0]->right->right->val, 3);
  }
  {
    EXPECT_EQ(actual[1]->val, 1);
    EXPECT_EQ(actual[1]->right->val, 3);
    EXPECT_EQ(actual[1]->right->left->val, 2);
  }
  {
    EXPECT_EQ(actual[2]->val, 2);
    EXPECT_EQ(actual[2]->left->val, 1);
    EXPECT_EQ(actual[2]->right->val, 3);
  }
  {
    EXPECT_EQ(actual[3]->val, 3);
    EXPECT_EQ(actual[3]->left->val, 1);
    EXPECT_EQ(actual[3]->left->right->val, 2);
  }
  {
    EXPECT_EQ(actual[4]->val, 3);
    EXPECT_EQ(actual[4]->left->val, 2);
    EXPECT_EQ(actual[4]->left->left->val, 1);
  }
  for (TreeNode* node : actual) {
    DeleteTreeNode(node);
  }

  exit(EXIT_SUCCESS);
}
