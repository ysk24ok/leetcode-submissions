#include "../leetcode/tree.hpp"

#include <vector>

#include "gtest/gtest.h"

namespace LeetCode {

TEST(CreateTreeNodeTest, normal_string) {
  //      1
  //     / \
  //    2   3
  //   /
  //  4
  std::string s("1 2 3 4 ;");
  TreeNode* got = CreateTreeNode(s);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->left->val);
  EXPECT_EQ(3, got->right->val);
  EXPECT_EQ(4, got->left->left->val);
  EXPECT_EQ(nullptr, got->left->right);
  EXPECT_EQ(nullptr, got->right->left);
  EXPECT_EQ(nullptr, got->right->right);
  EXPECT_EQ(nullptr, got->left->left->left);
  EXPECT_EQ(nullptr, got->left->left->right);
  DeleteTreeNode(got);
}


TEST(CreateTreeNodeTest, string_with_empty_node) {
  //      1
  //       \
  //        2
  //       /
  //      3
  std::string s("1 # 2 # # 3 ;");
  TreeNode* got = CreateTreeNode(s);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(nullptr, got->left);
  EXPECT_EQ(2, got->right->val);
  EXPECT_EQ(3, got->right->left->val);
  EXPECT_EQ(nullptr, got->right->right);
  EXPECT_EQ(nullptr, got->right->left->left);
  EXPECT_EQ(nullptr, got->right->left->right);
  DeleteTreeNode(got);
}

TEST(CreateTreeNodeTest, from_empty_string) {
  std::string s;
  TreeNode* got = CreateTreeNode(s);
  EXPECT_EQ(nullptr, got);
  DeleteTreeNode(got);
}

} // namespace LeetCode
