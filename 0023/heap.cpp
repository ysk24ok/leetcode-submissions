#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto greater = [](ListNode* left, ListNode* right) { return left->val > right->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(greater)> pq(greater);
    for (ListNode* list : lists) {
      if (!list) { continue; }
      pq.push(list);
    }
    ListNode dummy;
    ListNode* prev = &dummy;
    while (!pq.empty()) {
      ListNode* curr = pq.top();
      pq.pop();
      prev->next = new ListNode(curr->val);
      prev = prev->next;
      if (curr->next) {
        pq.push(curr->next);
      }
    }
    return dummy.next;
  }
};

int main() {
  Solution sol;
  vector<ListNode*> lists;
  ListNode* got;

  lists = {
    CreateListNode({1, 4, 5}),
    CreateListNode({1, 3, 4}),
    CreateListNode({2, 6}),
  };
  got = sol.mergeKLists(lists);
  EXPECT_EQ(1, got->val);
  EXPECT_EQ(1, got->next->val);
  EXPECT_EQ(2, got->next->next->val);
  EXPECT_EQ(3, got->next->next->next->val);
  EXPECT_EQ(4, got->next->next->next->next->val);
  EXPECT_EQ(4, got->next->next->next->next->next->val);
  EXPECT_EQ(5, got->next->next->next->next->next->next->val);
  EXPECT_EQ(6, got->next->next->next->next->next->next->next->val);
  EXPECT_FALSE(got->next->next->next->next->next->next->next->next);
  for (ListNode* list : lists) {
    DeleteListNode(list);
  }
  DeleteListNode(got);

  exit(EXIT_SUCCESS);
}
