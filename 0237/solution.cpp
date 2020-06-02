#include <cstdlib>
#include <vector>

#include "gtest/gtest.h"
#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  void deleteNode(ListNode* node) {
    ListNode* next_node = node->next;
    node->val = next_node->val;
    node->next = next_node->next;
    delete next_node;
  }
};

int main() {
  Solution sol;
  ListNode* head;

  head = CreateListNode({4,5,1,9});
  sol.deleteNode(head->next->next);
  EXPECT_EQ(4, head->val);
  EXPECT_EQ(5, head->next->val);
  EXPECT_EQ(9, head->next->next->val);
  EXPECT_FALSE(head->next->next->next);
  DeleteListNode(head);

  head = CreateListNode({4,5,1,9});
  sol.deleteNode(head->next);
  EXPECT_EQ(4, head->val);
  EXPECT_EQ(1, head->next->val);
  EXPECT_EQ(9, head->next->next->val);
  EXPECT_FALSE(head->next->next->next);
  DeleteListNode(head);

  exit(EXIT_SUCCESS);
}
