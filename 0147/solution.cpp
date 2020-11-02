#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head) { return nullptr; }
    ListNode dummy = ListNode(0, head);
    ListNode* prev = dummy.next;
    ListNode* curr = prev->next;
    while (curr) {
      while (curr && prev->val > curr->val) {
        prev->next = curr->next;
        curr->next = nullptr;
        searchAndInsert(&dummy, curr);
        curr = prev->next;
        if (!curr) { return dummy.next; }
      }
      prev = curr;
      curr = curr->next;
    }
    return dummy.next;
  }

 private:
  void searchAndInsert(ListNode* dummy, ListNode* node_to_insert) {
    ListNode* prev = dummy;
    ListNode* curr = dummy->next;
    while (curr) {
      if (node_to_insert->val < curr->val) {
        prev->next = node_to_insert;
        node_to_insert->next = curr;
        break;
      }
      prev = curr;
      curr = curr->next;
    }
  }
};

int main() {
  Solution sol;
  ListNode *head, *got;

  head = CreateListNode({4, 2, 1, 3});
  got = sol.insertionSortList(head);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_EQ(3, got->next->next->val);
  EXPECT_EQ(4, got->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next);
  DeleteListNode(got);

  head = CreateListNode({-1, 5, 3, 4, 0});
  got = sol.insertionSortList(head);
  EXPECT_EQ(-1, got->val);
  EXPECT_EQ(0, got->next->val);
  EXPECT_EQ(3, got->next->next->val);
  EXPECT_EQ(4, got->next->next->next->val);
  EXPECT_EQ(5, got->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next);
  DeleteListNode(got);

  head = CreateListNode({0});
  got = sol.insertionSortList(head);
  EXPECT_EQ(0, got->val);
  EXPECT_FALSE(got->next);
  DeleteListNode(got);

  EXPECT_FALSE(sol.insertionSortList(nullptr));

  exit(EXIT_SUCCESS);
}
