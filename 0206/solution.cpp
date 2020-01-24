#include <cassert>
#include <iostream>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;
    ListNode* node = head->next;
    ListNode* next = new ListNode(head->val);
    ListNode* curr;
    while (node) {
      curr = new ListNode(node->val);
      curr->next = next;
      node = node->next;
      next = curr;
    }
    return next;
  }
};

int main() {
  Solution sol;
  vector<int> vec;
  ListNode* node;
  ListNode* got;

  vec = {1,2,3,4,5};
  node = CreateListNode(vec);
  got = sol.reverseList(node);
  assert(got->val == 5);
  assert(got->next->val == 4);
  assert(got->next->next->val == 3);
  assert(got->next->next->next->val == 2);
  assert(got->next->next->next->next->val == 1);
  assert(!got->next->next->next->next->next);
  DeleteListNode(node);
  DeleteListNode(got);

  assert(!sol.reverseList(nullptr));
}
