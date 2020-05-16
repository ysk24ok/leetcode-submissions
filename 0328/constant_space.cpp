#include <vector>

#include "gtest/gtest.h"

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) { return head; }
    ListNode* prev_odd_node = head;
    ListNode* curr_odd_node = head->next->next;
    ListNode* next_odd_node = nullptr;
    ListNode* curr_last_even_node = head->next;
    ListNode* next_last_even_node = nullptr;
    while (curr_odd_node) {
      if (curr_odd_node->next) {
        next_last_even_node = curr_odd_node->next;
        next_odd_node = curr_odd_node->next->next;
      } else {
        next_last_even_node = nullptr;
        next_odd_node = nullptr;
      }
      ListNode* first_even_node = prev_odd_node->next;
      ListNode* remaining_node = curr_odd_node->next;
      prev_odd_node->next = curr_odd_node;
      curr_odd_node->next = first_even_node;
      curr_last_even_node->next = remaining_node;
      prev_odd_node = curr_odd_node;
      curr_odd_node = next_odd_node;
      curr_last_even_node = next_last_even_node;
    }
    return head;
  }
};

int main() {
  Solution sol;
  vector<int> nodes;
  ListNode* head = nullptr;
  ListNode* got = nullptr;

  EXPECT_FALSE(sol.oddEvenList(nullptr));

  head = new ListNode(1);
  got = sol.oddEvenList(head);
  EXPECT_EQ(1, head->val);
  delete head;

  nodes = {1,2};
  head = CreateListNode(nodes);
  got = sol.oddEvenList(head);
  EXPECT_EQ(1, head->val);
  EXPECT_EQ(2, head->next->val);
  EXPECT_FALSE(head->next->next);
  DeleteListNode(head);

  nodes = {1,2,3};
  head = CreateListNode(nodes);
  got = sol.oddEvenList(head);
  EXPECT_EQ(1, head->val);
  EXPECT_EQ(3, head->next->val);
  EXPECT_EQ(2, head->next->next->val);
  EXPECT_FALSE(head->next->next->next);
  DeleteListNode(head);

  nodes = {1,2,3,4};
  head = CreateListNode(nodes);
  got = sol.oddEvenList(head);
  EXPECT_EQ(1, head->val);
  EXPECT_EQ(3, head->next->val);
  EXPECT_EQ(2, head->next->next->val);
  EXPECT_EQ(4, head->next->next->next->val);
  EXPECT_FALSE(head->next->next->next->next);
  DeleteListNode(head);

  nodes = {1,2,3,4,5};
  head = CreateListNode(nodes);
  got = sol.oddEvenList(head);
  EXPECT_EQ(1, head->val);
  EXPECT_EQ(3, head->next->val);
  EXPECT_EQ(5, head->next->next->val);
  EXPECT_EQ(2, head->next->next->next->val);
  EXPECT_EQ(4, head->next->next->next->next->val);
  EXPECT_FALSE(head->next->next->next->next->next);
  DeleteListNode(head);

  nodes = {1,2,3,4,5,6};
  head = CreateListNode(nodes);
  got = sol.oddEvenList(head);
  EXPECT_EQ(1, head->val);
  EXPECT_EQ(3, head->next->val);
  EXPECT_EQ(5, head->next->next->val);
  EXPECT_EQ(2, head->next->next->next->val);
  EXPECT_EQ(4, head->next->next->next->next->val);
  EXPECT_EQ(6, head->next->next->next->next->next->val);
  EXPECT_FALSE(head->next->next->next->next->next->next);
  DeleteListNode(head);

  nodes = {1,2,3,4,5,6,7};
  head = CreateListNode(nodes);
  got = sol.oddEvenList(head);
  EXPECT_EQ(1, head->val);
  EXPECT_EQ(3, head->next->val);
  EXPECT_EQ(5, head->next->next->val);
  EXPECT_EQ(7, head->next->next->next->val);
  EXPECT_EQ(2, head->next->next->next->next->val);
  EXPECT_EQ(4, head->next->next->next->next->next->val);
  EXPECT_EQ(6, head->next->next->next->next->next->next->val);
  EXPECT_FALSE(head->next->next->next->next->next->next->next);
  DeleteListNode(head);
}
