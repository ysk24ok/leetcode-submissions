#include "../leetcode/tree.hpp"

#include <vector>

#include "gtest/gtest.h"

namespace LeetCode {

TEST(CreateTreeNodeVectorTest, normal_vector) {
  std::vector<int> vec = {3, NULL};
  std::vector<TreeNode*> got = CreateTreeNodeVector(vec);
  EXPECT_EQ(2, got.size());
  EXPECT_EQ(3, got[0]->val);
  EXPECT_EQ(NULL, got[0]->left);
  EXPECT_EQ(NULL, got[0]->right);
  EXPECT_EQ(NULL, got[1]->val);
  EXPECT_EQ(NULL, got[1]->left);
  EXPECT_EQ(NULL, got[1]->right);
  DeleteTreeNodeVector(got);
}

TEST(CreateTreeNodeVectorTest, empty_vector) {
  std::vector<int> vec;
  std::vector<TreeNode*> got = CreateTreeNodeVector(vec);
  EXPECT_EQ(0, got.size());
}

TEST(CreateTreeNodeTest, normal_vector) {
  std::vector<int> vec = {3, 9, 20, NULL, NULL, 15, 7};
  std::vector<TreeNode*> node_vec = CreateTreeNodeVector(vec);
  TreeNode* got = CreateTreeNode(node_vec);
  EXPECT_EQ(3, got->val);
  EXPECT_EQ(9, got->left->val);
  EXPECT_EQ(20, got->right->val);
  EXPECT_EQ(NULL, got->left->left);
  EXPECT_EQ(NULL, got->left->right);
  EXPECT_EQ(15, got->right->left->val);
  EXPECT_EQ(7, got->right->right->val);
  EXPECT_EQ(NULL, got->right->left->left);
  EXPECT_EQ(NULL, got->right->left->right);
  EXPECT_EQ(NULL, got->right->right->left);
  EXPECT_EQ(NULL, got->right->right->right);
}

TEST(CreateTreeNodeTest, empty_vector) {
  std::vector<int> vec;
  std::vector<TreeNode*> node_vec = CreateTreeNodeVector(vec);
  TreeNode* got = CreateTreeNode(node_vec);
  EXPECT_EQ(NULL, got);
}

} // namespace LeetCode
