#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (!head) { return false; }
    ListNode *faster = head->next, *slower = head;
    while (faster && faster->next) {
      if (faster == slower) {
        return true;
      }
      faster = faster->next->next;
      slower = slower->next;
    }
    return false;
  }
};

int main() {
  Solution sol;
  ListNode* head;
  bool expected;

  head = CreateListNode({3, 2, 0, -4}), expected = true;
  head->next->next->next->next = head->next;
  EXPECT_EQ(expected, sol.hasCycle(head));
  head->next->next->next->next = nullptr;
  DeleteListNode(head);

  head = CreateListNode({1, 2}), expected = true;
  head->next->next = head;
  EXPECT_EQ(expected, sol.hasCycle(head));
  head->next->next = nullptr;
  DeleteListNode(head);

  head = CreateListNode({1}), expected = false;
  EXPECT_EQ(expected, sol.hasCycle(head));
  DeleteListNode(head);

  exit(EXIT_SUCCESS);
}
