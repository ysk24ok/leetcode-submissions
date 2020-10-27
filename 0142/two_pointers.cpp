#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) { return nullptr; }
    ListNode *faster = head, *slower = head;
    faster = faster->next->next;
    slower = slower->next;
    while (faster != slower) {
      // no cycle
      if (!faster || !faster->next) { return nullptr; }
      faster = faster->next->next;
      slower = slower->next;
    }
    ListNode *node = head;
    while (node != slower) {
      node = node->next;
      slower = slower->next;
    }
    return node;
  }
};

int main() {
  Solution sol;
  vector<int> nodes;
  ListNode *head;
  int expected;

  nodes = {3, 2, 0, -4};
  head = CreateListNode(nodes);
  head->next->next->next->next = head->next;
  expected = 2;
  EXPECT_EQ(expected, sol.detectCycle(head)->val);
  DeleteListNode(head, nodes.size());

  nodes = {1, 2};
  head = CreateListNode(nodes);
  head->next->next = head;
  expected = 1;
  EXPECT_EQ(expected, sol.detectCycle(head)->val);
  DeleteListNode(head, nodes.size());

  head = CreateListNode({1});
  EXPECT_FALSE(sol.detectCycle(head));
  DeleteListNode(head);

  head = CreateListNode({1, 2});
  EXPECT_FALSE(sol.detectCycle(head));
  DeleteListNode(head);

  head = CreateListNode({1, 2, 3});
  EXPECT_FALSE(sol.detectCycle(head));
  DeleteListNode(head);

  exit(EXIT_SUCCESS);
}
