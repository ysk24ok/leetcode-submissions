#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    size_t count1 = count(l1);
    size_t count2 = count(l2);
    l1 = reverse(l1);
    l2 = reverse(l2);
    if (count1 < count2) {
      ListNode* tmp = l1;
      l1 = l2;
      l2 = tmp;
    }
    ListNode dummy(0);
    dummy.next = l1;
    ListNode* prev = &dummy;
    int carry_up = 0;
    while (l1 && l2) {
      l1->val += l2->val + carry_up;
      carry_up = l1->val / 10;
      l1->val %= 10;
      prev = l1;
      l1 = l1->next;
      l2 = l2->next;
    }
    while (carry_up > 0) {
      if (l1) {
        l1->val += carry_up;
      } else {
        l1 = new ListNode(carry_up);
        prev->next = l1;
      }
      carry_up = l1->val / 10;
      l1->val %= 10;
      prev = l1;
      l1 = l1->next;
    }
    return reverse(dummy.next);
  }

 private:
  ListNode* reverse(ListNode* node) {
    if (!node) { return nullptr; }
    ListNode* next = node;
    ListNode* curr = node->next;
    next->next = nullptr;
    while (curr) {
      ListNode* new_curr = curr->next;
      curr->next = next;
      next = curr;
      curr = new_curr;
    }
    return next;
  }

  size_t count(ListNode* node) {
    size_t i = 0;
    while (node) {
      i++;
      node = node->next;
    }
    return i;
  }
};

int main() {
  Solution sol;
  ListNode *l1, *l2, *got;

  l1 = CreateListNode({7, 2, 4, 3});
  l2 = CreateListNode({5, 6, 4});
  got = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(7, got->val);
  EXPECT_EQ(8, got->next->val);
  EXPECT_EQ(0, got->next->next->val);
  EXPECT_EQ(7, got->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next);
  DeleteListNode(got);

  l1 = CreateListNode({1});
  l2 = CreateListNode({9, 9});
  got = sol.addTwoNumbers(l1, l2);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(0, got->next->val);
  EXPECT_EQ(0, got->next->next->val);
  EXPECT_FALSE(got->next->next->next);
  DeleteListNode(got);

  exit(EXIT_SUCCESS);
}
