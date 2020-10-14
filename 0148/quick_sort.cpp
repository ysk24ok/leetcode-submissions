#include <gtest/gtest.h>

#include <cstdlib>
#include <numeric>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    return divideAndConquer(head);
  }

  ListNode* divideAndConquer(ListNode* head) {
    if (!head || !head->next) { return head; }
    int pivot = head->val;
    ListNode smaller_dummy = ListNode(0);
    ListNode larger_dummy = ListNode(0);
    ListNode* smaller = &smaller_dummy;
    ListNode* larger = &larger_dummy;
    while (head) {
      if (head->val >= pivot) {
        larger->next = head;
        larger = larger->next;
      } else {
        smaller->next = head;
        smaller = smaller->next;
      }
      head = head->next;
    }
    smaller->next = nullptr;
    larger->next = nullptr;
    // If node->val >= pivot, the node is added to a larger partition,
    // so there is a case that a smaller partition is empty (e.g. 2,5,3,4).
    if (!smaller_dummy.next) {
      smaller_dummy.next = larger_dummy.next;
      larger_dummy.next = larger_dummy.next->next;
      smaller_dummy.next->next = nullptr;
    }
    ListNode* smaller_head = divideAndConquer(smaller_dummy.next);
    ListNode* larger_head = divideAndConquer(larger_dummy.next);
    if (!smaller_head) { return larger_head; }
    smaller = smaller_head;
    while (smaller->next) {
      smaller = smaller->next;
    }
    smaller->next = larger_head;
    return smaller_head;
  }
};

int main() {
  Solution sol;
  ListNode* head;
  ListNode* got;

  head = CreateListNode({4, 2, 1, 3});
  got = sol.sortList(head);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_EQ(3, got->next->next->val);
  EXPECT_EQ(4, got->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next);

  head = CreateListNode({-1, 5, 3, 4, 0});
  got = sol.sortList(head);
  EXPECT_EQ(-1, got->val);
  EXPECT_EQ(0, got->next->val);
  EXPECT_EQ(3, got->next->next->val);
  EXPECT_EQ(4, got->next->next->next->val);
  EXPECT_EQ(5, got->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next);

  EXPECT_FALSE(sol.sortList(nullptr));

  head = CreateListNode({1, 2});
  got = sol.sortList(head);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_FALSE(got->next->next);

  head = CreateListNode({2, 1});
  got = sol.sortList(head);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_FALSE(got->next->next);

  exit(EXIT_SUCCESS);
}
