#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int getDecimalValue(ListNode* head) {
    int ret = 0;
    while (head) {
      ret <<= 1;
      ret += head->val;
      head = head->next;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  ListNode* head;
  int expected;

  head = CreateListNode({1, 0, 1});
  expected = 5;
  EXPECT_EQ(expected, sol.getDecimalValue(head));
  DeleteListNode(head);

  head = CreateListNode({0});
  expected = 0;
  EXPECT_EQ(expected, sol.getDecimalValue(head));
  DeleteListNode(head);

  head = CreateListNode({1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0});
  expected = 18880;
  EXPECT_EQ(expected, sol.getDecimalValue(head));
  DeleteListNode(head);

  head = CreateListNode({0, 0});
  expected = 0;
  EXPECT_EQ(expected, sol.getDecimalValue(head));
  DeleteListNode(head);

  head = CreateListNode({1});
  expected = 1;
  EXPECT_EQ(expected, sol.getDecimalValue(head));
  DeleteListNode(head);

  exit(EXIT_SUCCESS);
}
