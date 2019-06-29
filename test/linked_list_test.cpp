#include "../leetcode/linked_list.hpp"

#include <vector>

#include "gtest/gtest.h"

namespace LeetCode {

TEST(CreateListNodeTest, normal_vector) {
  std::vector<int> vec = {3, 5, 9};
  ListNode* got = CreateListNode(vec);
  EXPECT_EQ(3, got->val);
  EXPECT_EQ(5, got->next->val);
  EXPECT_EQ(9, got->next->next->val);
  EXPECT_EQ(nullptr, got->next->next->next);
  DeleteListNode(got);
}

TEST(CreateListNodeTest, vector_whose_size_is_1) {
  std::vector<int> vec = {3};
  ListNode* got = CreateListNode(vec);
  EXPECT_EQ(3, got->val);
  EXPECT_EQ(nullptr, got->next);
  DeleteListNode(got);
}

TEST(CreateListNodeTest, empty_vector) {
  std::vector<int> vec = {};
  ListNode* got = CreateListNode(vec);
  EXPECT_EQ(nullptr, got);
  DeleteListNode(got);
}

} // namespace LeetCode
