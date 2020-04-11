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

TEST(AssertListNodeEqual, equal) {
  ListNode* expected = CreateListNode({1, 2, 3, 4});
  ListNode* actual = CreateListNode({1, 2, 3, 4});
  EXPECT_NO_FATAL_FAILURE(AssertListNodeEqual(expected, actual));
  DeleteListNode(expected);
  DeleteListNode(actual);
}

TEST(AssertListNodeEqual, not_equal) {
  EXPECT_DEATH({
    ListNode* expected = CreateListNode({1, 2, 3, 4});
    ListNode* actual = CreateListNode({1, 2, 3, 5});
    AssertListNodeEqual(expected, actual);
    DeleteListNode(expected);
    DeleteListNode(actual);
  }, "");
}

TEST(AssertListNodeEqual, not_equal_length) {
  EXPECT_DEATH({
    ListNode* expected = CreateListNode({1, 2, 3, 4});
    ListNode* actual = CreateListNode({1, 2, 3, 4, 5});
    AssertListNodeEqual(expected, actual);
    DeleteListNode(expected);
    DeleteListNode(actual);
  }, "");
}

} // namespace LeetCode
