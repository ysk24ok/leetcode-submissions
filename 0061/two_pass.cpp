#include <gtest/gtest.h>

#include <cstdlib>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) { return nullptr; }
    size_t count = 0;
    ListNode* node = head;
    while (node) {
      count++;
      node = node->next;
    }
    k %= count;
    int num_moves = count - k - 1;
    int curr_num_moves = 0;
    node = head;
    while (curr_num_moves < num_moves) {
      node = node->next;
      curr_num_moves++;
    }
    if (!node->next) { return head; }
    ListNode* new_head = node->next;
    node->next = nullptr;
    node = new_head;
    while (node->next) {
      node = node->next;
    }
    node->next = head;
    return new_head;
  }
};

int main() {
  Solution sol;
  ListNode* head;
  ListNode* got;
  int k;

  head = CreateListNode({1, 2, 3, 4, 5}), k = 2;
  got = sol.rotateRight(head, k);
  EXPECT_EQ(4, got->val);
  EXPECT_EQ(5, got->next->val);
  EXPECT_EQ(1, got->next->next->val);
  EXPECT_EQ(2, got->next->next->next->val);
  EXPECT_EQ(3, got->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next);
  DeleteListNode(got);

  head = CreateListNode({1, 2, 3, 4, 5}), k = 5;
  got = sol.rotateRight(head, k);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_EQ(3, got->next->next->val);
  EXPECT_EQ(4, got->next->next->next->val);
  EXPECT_EQ(5, got->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next);
  DeleteListNode(got);

  head = nullptr, k = 0;
  got = sol.rotateRight(head, k);
  EXPECT_FALSE(got);

  head = CreateListNode({1}), k = 1;
  got = sol.rotateRight(head, k);
  EXPECT_EQ(1, got->val);
  EXPECT_FALSE(got->next);
  DeleteListNode(got);

  exit(EXIT_SUCCESS);
}
