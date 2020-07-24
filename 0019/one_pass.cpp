#include <vector>

#include "gtest/gtest.h"
#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* curr = dummy.next;
    ListNode* ptr = curr;
    while (n > 0) {
      ptr = ptr->next;
      n--;
    }
    while (ptr) {
      prev = prev->next;
      curr = curr->next;
      ptr = ptr->next;
    }
    // only when head is nullptr
    if (curr) {
      prev->next = curr->next;
      delete curr;
    }
    return dummy.next;
  }
};

int main() {
  Solution sol;
  ListNode* head;
  ListNode* got;
  vector<int> vec;

  vec = {1,2,3,4,5};
  head = CreateListNode(vec);
  got = sol.removeNthFromEnd(head, 2);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_EQ(3, got->next->next->val);
  EXPECT_EQ(5, got->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next);
  DeleteListNode(got);

  vec = {1,2};
  head = CreateListNode(vec);
  got = sol.removeNthFromEnd(head, 2);
  EXPECT_EQ(2, got->val);
  EXPECT_FALSE(got->next);
  DeleteListNode(got);

  vec = {1};
  head = CreateListNode(vec);
  got = sol.removeNthFromEnd(head, 1);
  EXPECT_FALSE(got);

  got = sol.removeNthFromEnd(nullptr, 0);
  EXPECT_FALSE(got);
}
