#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* prev = &dummy;
    int carry_over = 0;
    int curr_val = 0;
    while (l1 && l2) {
      curr_val = l1->val + l2->val + carry_over;
      carry_over = curr_val / 10;
      prev->next = new ListNode(curr_val % 10);
      l1 = l1->next;
      l2 = l2->next;
      prev = prev->next;
    }
    while (l1) {
      curr_val = l1->val + carry_over;
      carry_over = curr_val / 10;
      prev->next = new ListNode(curr_val % 10);
      l1 = l1->next;
      prev = prev->next;
    }
    while (l2) {
      curr_val = l2->val + carry_over;
      carry_over = curr_val / 10;
      prev->next = new ListNode(curr_val % 10);
      l2 = l2->next;
      prev = prev->next;
    }
    if (carry_over > 0) {
      prev->next = new ListNode(carry_over);
    }
    return dummy.next;
  }
};

int main() {
  Solution sol;
  ListNode *l1, *l2, *got;

  l1 = CreateListNode({2, 4, 3});
  l2 = CreateListNode({5, 6, 4});
  got = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(7, got->val);
  EXPECT_EQ(0, got->next->val);
  EXPECT_EQ(8, got->next->next->val);
  EXPECT_FALSE(got->next->next->next);
  DeleteListNode(l1);
  DeleteListNode(l2);
  DeleteListNode(got);

  l1 = CreateListNode({0});
  l2 = CreateListNode({0});
  got = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(0, got->val);
  EXPECT_FALSE(got->next);
  DeleteListNode(l1);
  DeleteListNode(l2);
  DeleteListNode(got);

  l1 = CreateListNode({9, 9, 9, 9, 9, 9, 9});
  l2 = CreateListNode({9, 9, 9, 9});
  got = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(8, got->val);
  EXPECT_EQ(9, got->next->val);
  EXPECT_EQ(9, got->next->next->val);
  EXPECT_EQ(9, got->next->next->next->val);
  EXPECT_EQ(0, got->next->next->next->next->val);
  EXPECT_EQ(0, got->next->next->next->next->next->val);
  EXPECT_EQ(0, got->next->next->next->next->next->next->val);
  EXPECT_EQ(1, got->next->next->next->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next->next->next->next);
  DeleteListNode(l1);
  DeleteListNode(l2);
  DeleteListNode(got);

  exit(EXIT_SUCCESS);
}
