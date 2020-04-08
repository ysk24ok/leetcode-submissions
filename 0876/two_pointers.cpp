#include <cassert>
#include <iostream>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode* first = head;
    ListNode* second = head->next;
    while (second) {
      second = second->next;
      first = first->next;
      if (!second) break;
      second = second->next;
      if (!second) break;
    }
    return first;
  }
};

int main() {
  Solution sol;
  vector<int> vec;
  ListNode* head;

  vec = {1,2,3,4,5};
  head = CreateListNode(vec);
  assert(sol.middleNode(head)->val == 3);
  DeleteListNode(head);

  vec = {1,2,3,4,5,6};
  head = CreateListNode(vec);
  assert(sol.middleNode(head)->val == 4);
  DeleteListNode(head);

  vec = {1};
  head = CreateListNode(vec);
  assert(sol.middleNode(head)->val == 1);
  DeleteListNode(head);

  vec = {1,2};
  head = CreateListNode(vec);
  assert(sol.middleNode(head)->val == 2);
  DeleteListNode(head);

  vec = {1,2,3};
  head = CreateListNode(vec);
  assert(sol.middleNode(head)->val == 2);
  DeleteListNode(head);
}
