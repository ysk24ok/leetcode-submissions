#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode *faster = head, *slower = head;
    int i = 1;
    while (i < k) {
      faster = faster->next;
      ++i;
    }
    ListNode* a = faster;
    while (faster->next) {
      faster = faster->next;
      slower = slower->next;
    }
    swap(a, slower);
    return head;
  }

  void swap(ListNode* a, ListNode* b) {
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
  }
};

int main() {
  Solution sol;
  ListNode *head, *got;
  int k;

  head = CreateListNode({1, 2, 3, 4, 5}), k = 2;
  got = sol.swapNodes(head, k);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(4, got->next->val);
  EXPECT_EQ(3, got->next->next->val);
  EXPECT_EQ(2, got->next->next->next->val);
  EXPECT_EQ(5, got->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next);

  head = CreateListNode({7, 9, 6, 6, 7, 8, 3, 0, 9, 5}), k = 2;
  got = sol.swapNodes(head, k);
  EXPECT_EQ(7, got->val);
  EXPECT_EQ(9, got->next->val);
  EXPECT_EQ(6, got->next->next->val);
  EXPECT_EQ(6, got->next->next->next->val);
  EXPECT_EQ(7, got->next->next->next->next->val);
  EXPECT_EQ(8, got->next->next->next->next->next->val);
  EXPECT_EQ(3, got->next->next->next->next->next->next->val);
  EXPECT_EQ(0, got->next->next->next->next->next->next->next->val);
  EXPECT_EQ(9, got->next->next->next->next->next->next->next->next->val);
  EXPECT_EQ(5, got->next->next->next->next->next->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next->next->next->next->next->next);

  head = CreateListNode({1}), k = 1;
  got = sol.swapNodes(head, k);
  EXPECT_EQ(1, got->val);
  EXPECT_FALSE(got->next);

  head = CreateListNode({1, 2}), k = 1;
  got = sol.swapNodes(head, k);
  EXPECT_EQ(2, got->val);
  EXPECT_EQ(1, got->next->val);
  EXPECT_FALSE(got->next->next);

  head = CreateListNode({1, 2, 3}), k = 2;
  got = sol.swapNodes(head, k);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_EQ(3, got->next->next->val);
  EXPECT_FALSE(got->next->next->next);

  exit(EXIT_SUCCESS);
}
