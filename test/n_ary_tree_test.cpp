#include "../leetcode/n_ary_tree.hpp"

#include "gtest/gtest.h"

namespace LeetCode {

TEST(CreateNode, normal_1) {
  std::string s("1 # 2 3 4 # 5 6");
  Node* actual = CreateNode(s);
  EXPECT_EQ(1, actual->val);
  ASSERT_EQ(3, actual->children.size());
  EXPECT_EQ(2, actual->children[0]->val);
  EXPECT_EQ(3, actual->children[1]->val);
  EXPECT_EQ(4, actual->children[2]->val);
  ASSERT_EQ(2, actual->children[0]->children.size());
  EXPECT_EQ(5, actual->children[0]->children[0]->val);
  EXPECT_EQ(6, actual->children[0]->children[1]->val);
  EXPECT_TRUE(actual->children[1]->children.empty());
  EXPECT_TRUE(actual->children[2]->children.empty());
  DeleteNode(actual);
}

TEST(CreateNode, normal_2) {
  std::string s("1 # 2 3 4 # # 5 6");
  Node* actual = CreateNode(s);
  EXPECT_EQ(1, actual->val);
  ASSERT_EQ(3, actual->children.size());
  EXPECT_EQ(2, actual->children[0]->val);
  EXPECT_EQ(3, actual->children[1]->val);
  EXPECT_EQ(4, actual->children[2]->val);
  EXPECT_TRUE(actual->children[0]->children.empty());
  ASSERT_EQ(2, actual->children[1]->children.size());
  EXPECT_EQ(5, actual->children[1]->children[0]->val);
  EXPECT_EQ(6, actual->children[1]->children[1]->val);
  EXPECT_TRUE(actual->children[2]->children.empty());
  DeleteNode(actual);
}

TEST(CreateNode, only_root_1) {
  std::string s("1");
  Node* actual = CreateNode(s);
  EXPECT_EQ(1, actual->val);
  EXPECT_TRUE(actual->children.empty());
  DeleteNode(actual);
}

TEST(CreateNode, only_root_2) {
  std::string s("1 #");
  Node* actual = CreateNode(s);
  EXPECT_EQ(1, actual->val);
  EXPECT_TRUE(actual->children.empty());
  DeleteNode(actual);
}

}  // namespace LeetCode