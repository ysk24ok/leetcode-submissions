#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "../leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy;
    ListNode* prev = &dummy;
    while (head) {
      if (!head->next || head->val != head->next->val) {
        prev->next = head;
        prev = prev->next;
      }
      head = head->next;
    }
    return dummy.next;
  }
};

int main() {
  Solution sol;
  std::vector<int> vec;
  ListNode *head, *got;

  got = sol.deleteDuplicates(nullptr);
  EXPECT_FALSE(got);

  vec = {1, 1, 2};
  head = CreateListNode(vec);
  got = sol.deleteDuplicates(head);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_FALSE(got->next->next);
  DeleteListNode(head);

  vec = {1, 1, 2, 3, 3};
  head = CreateListNode(vec);
  got = sol.deleteDuplicates(head);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_EQ(3, got->next->next->val);
  EXPECT_FALSE(got->next->next->next);
  DeleteListNode(head);

  exit(EXIT_SUCCESS);
}
