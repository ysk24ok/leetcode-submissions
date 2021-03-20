#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
      return l2;
    } else if (!l2) {
      return l1;
    } else if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
};

int main() {
  Solution sol;
  ListNode *l1, *l2, *got;

  l1 = CreateListNode({1, 2, 4}), l2 = CreateListNode({1, 3, 4});
  got = sol.mergeTwoLists(l1, l2);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(1, got->next->val);
  EXPECT_EQ(2, got->next->next->val);
  EXPECT_EQ(3, got->next->next->next->val);
  EXPECT_EQ(4, got->next->next->next->next->val);
  EXPECT_EQ(4, got->next->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next->next);
  DeleteListNode(got);

  l1 = nullptr, l2 = nullptr;
  got = sol.mergeTwoLists(l1, l2);
  EXPECT_FALSE(got);

  l1 = CreateListNode({1, 2}), l2 = nullptr;
  got = sol.mergeTwoLists(l1, l2);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(2, got->next->val);
  EXPECT_FALSE(got->next->next);


  exit(EXIT_SUCCESS);
}
