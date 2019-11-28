#include <cassert>
#include <vector>

#include "../leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return nullptr;
    // first pass to count the number of nodes
    ListNode* node = head;
    int num_nodes = 0;
    while (node != nullptr) {
      num_nodes++;
      node = node->next;
    }
    // second pass
    ListNode* ret = nullptr;
    ListNode* prev_node = nullptr;
    node = head;
    while (node != nullptr) {
      if (num_nodes != n) {
        ListNode* new_node = new ListNode(node->val);
        if (prev_node != nullptr) {
          prev_node->next = new_node;
          prev_node = new_node;
        } else {
          prev_node = new_node;
          ret = new_node;
        }
      }
      node = node->next;
      num_nodes--;
    }
    return ret;
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
  assert(got->val == 1);
  assert(got->next->val == 2);
  assert(got->next->next->val == 3);
  assert(got->next->next->next->val == 5);
  assert(!got->next->next->next->next);
  DeleteListNode(head);
  DeleteListNode(got);

  vec = {1,2};
  head = CreateListNode(vec);
  got = sol.removeNthFromEnd(head, 2);
  assert(got->val == 2);
  assert(!got->next);
  DeleteListNode(head);
  DeleteListNode(got);

  vec = {1};
  head = CreateListNode(vec);
  got = sol.removeNthFromEnd(head, 1);
  assert(!got);
  DeleteListNode(head);

  got = sol.removeNthFromEnd(nullptr, 0);
  assert(!got);
}
