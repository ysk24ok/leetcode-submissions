#include <cassert>
#include <iostream>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    swap(head);
    return head;
  }

  void swap(ListNode* node) {
    if (!node || !node->next) return;
    int tmp = node->val;
    node->val = node->next->val;
    node->next->val = tmp;
    swap(node->next->next);
  }
};

int main() {
  Solution sol;
  ListNode* head;
  ListNode* got;
  ListNode* expected;
  vector<int> vec;

  head = CreateListNode({1, 2, 3, 4});
  got = sol.swapPairs(head);
  expected = CreateListNode({2, 1, 4, 3});
  AssertListNodeEqual(expected, got);
  DeleteListNode(head);

  head = CreateListNode({1, 2, 3, 4, 5});
  got = sol.swapPairs(head);
  expected = CreateListNode({2, 1, 4, 3, 5});
  AssertListNodeEqual(expected, got);
  DeleteListNode(head);

  assert(!sol.swapPairs(nullptr));
}
