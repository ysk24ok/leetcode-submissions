#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> vec1, vec2;
    inorder(root1, vec1);
    inorder(root2, vec2);
    size_t ptr1 = 0, ptr2 = 0;
    vector<int> ret;
    ret.reserve(vec1.size() + vec2.size());
    while (ptr1 < vec1.size() && ptr2 < vec2.size()) {
      if (vec1[ptr1] > vec2[ptr2]) {
        ret.push_back(vec2[ptr2++]);
      } else {
        ret.push_back(vec1[ptr1++]);
      }
    }
    while (ptr1 < vec1.size()) {
        ret.push_back(vec1[ptr1++]);
    }
    while (ptr2 < vec2.size()) {
        ret.push_back(vec2[ptr2++]);
    }
    return ret;
  }

  void inorder(TreeNode* node, vector<int>& vec) {
    if (!node) { return; }
    inorder(node->left, vec);
    vec.push_back(node->val);
    inorder(node->right, vec);
  }
};

int main() {
  Solution sol;
  TreeNode *root1, *root2;
  vector<int> got, expected;

  root1 = CreateTreeNode("2 1 4");
  root2 = CreateTreeNode("1 0 3");
  expected = {0, 1, 1, 2, 3, 4};
  got = sol.getAllElements(root1, root2);
  EXPECT_EQ(expected, got);
  DeleteTreeNode(root1);
  DeleteTreeNode(root2);

  root1 = CreateTreeNode("0 -10 10");
  root2 = CreateTreeNode("5 1 7 0 2");
  expected = {-10, 0, 0, 1, 2, 5, 7, 10};
  got = sol.getAllElements(root1, root2);
  EXPECT_EQ(expected, got);
  DeleteTreeNode(root1);
  DeleteTreeNode(root2);

  root1 = CreateTreeNode("");
  root2 = CreateTreeNode("5 1 7 0 2");
  expected = {0, 1, 2, 5, 7};
  got = sol.getAllElements(root1, root2);
  EXPECT_EQ(expected, got);
  DeleteTreeNode(root1);
  DeleteTreeNode(root2);

  root1 = CreateTreeNode("0 -10 10");
  root2 = CreateTreeNode("");
  expected = {-10, 0, 10};
  got = sol.getAllElements(root1, root2);
  EXPECT_EQ(expected, got);
  DeleteTreeNode(root1);
  DeleteTreeNode(root2);

  root1 = CreateTreeNode("1 # 8");
  root2 = CreateTreeNode("8 1");
  expected = {1, 1, 8, 8};
  got = sol.getAllElements(root1, root2);
  EXPECT_EQ(expected, got);
  DeleteTreeNode(root1);
  DeleteTreeNode(root2);

  exit(EXIT_SUCCESS);
}
