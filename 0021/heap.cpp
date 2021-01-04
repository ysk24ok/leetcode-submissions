#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto greater = [] (const ListNode* left, const ListNode* right) {
      return left->val > right->val;
    };
    priority_queue<ListNode*, std::vector<ListNode*>, decltype(greater)> pq(greater);
    if (l1) { pq.push(l1); }
    if (l2) { pq.push(l2); }
    ListNode dummy;
    ListNode* prev = &dummy;
    while (!pq.empty()) {
      ListNode* node = pq.top();
      pq.pop();
      prev->next = node;
      prev = node;
      if (node->next) { pq.push(node->next); }
    }
    return dummy.next;
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
