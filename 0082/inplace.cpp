#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy;
    bool is_distinct = true;
    ListNode* curr = head;
    ListNode* prev = &dummy;
    while (curr) {
      if (!curr->next) {
        if (is_distinct) {
          prev->next = curr;
          prev = prev->next;
        }
      } else {
        if (curr->val == curr->next->val) {
          is_distinct = false;
        } else {
          if (is_distinct) {
            prev->next = curr;
            prev = prev->next;
          } else {
            is_distinct = true;
          }
        }
      }
      curr = curr->next;
    }
    prev->next = nullptr;
    return dummy.next;
  }
};

int main() {
  Solution sol;
  ListNode *head, *got;

  head = CreateListNode({1, 2, 3, 3, 4, 4, 5});
  got = sol.deleteDuplicates(head);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_EQ(5, got->next->next->val);
  EXPECT_FALSE(got->next->next->next);
  DeleteListNode(head);

  head = CreateListNode({1, 1, 1, 2, 3});
  got = sol.deleteDuplicates(head);
  EXPECT_EQ(2, got->val);
  EXPECT_EQ(3, got->next->val);
  EXPECT_FALSE(got->next->next);
  DeleteListNode(head);

  head = CreateListNode({1, 2, 3, 3, 3});
  got = sol.deleteDuplicates(head);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_FALSE(got->next->next);
  DeleteListNode(head);

  exit(EXIT_SUCCESS);
}
