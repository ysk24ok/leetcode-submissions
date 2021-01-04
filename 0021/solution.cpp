#include <gtest/gtest.h>

#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head(0);
    ListNode* prev = nullptr;
    ListNode* node;
    while (l1 || l2) {
      if (!l1) {
        node = new ListNode(l2->val);
        l2 = l2->next;
      } else if (!l2) {
        node = new ListNode(l1->val);
        l1 = l1->next;
      } else if (l1->val < l2->val) {
        node = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        node = new ListNode(l2->val);
        l2 = l2->next;
      }
      if (!prev) {
        head.next = node;
      } else {
        prev->next = node;
      }
      prev = node;
    }
    return head.next;
  }
};

int main() {
  Solution sol;
  ListNode* l1;
  ListNode* l2;
  ListNode* got;

  vector<int> v1 = {1,2,4};
  vector<int> v2 = {1,3,4};
  l1 = CreateListNode(v1);
  l2 = CreateListNode(v2);
  got = sol.mergeTwoLists(l1, l2);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(1, got->next->val);
  EXPECT_EQ(2, got->next->next->val);
  EXPECT_EQ(3, got->next->next->next->val);
  EXPECT_EQ(4, got->next->next->next->next->val);
  EXPECT_EQ(4, got->next->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next->next);
  DeleteListNode(l1);
  DeleteListNode(l2);
  DeleteListNode(got);

  got = sol.mergeTwoLists(nullptr, nullptr);
  EXPECT_FALSE(got);
}
