#include <cassert>
#include <vector>

#include "../leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
      return nullptr;
    ListNode* root = new ListNode(head->val);
    ListNode* prev = root;
    ListNode* prev_dup = head;
    while (prev_dup->next) {
      ListNode* node_dup = prev_dup->next;  // TODO
      if (node_dup->val != prev_dup->val) {
        prev->next = new ListNode(node_dup->val);
        prev = prev->next;
      }
      prev_dup = node_dup;
    }
    return root;
  }
};

int main() {
  Solution sol;
  std::vector<int> vec;
  ListNode* node;
  ListNode* got;

  got = sol.deleteDuplicates(nullptr);
  assert(got == nullptr);

  vec = {1, 1, 2};
  node = CreateListNode(vec);
  got = sol.deleteDuplicates(node);
  assert(got->val == 1);
  assert(got->next->val == 2);
  assert(got->next->next == nullptr);
  DeleteListNode(node);
  DeleteListNode(got);

  vec = {1, 1, 2, 3, 3};
  node = CreateListNode(vec);
  got = sol.deleteDuplicates(node);
  assert(got->val == 1);
  assert(got->next->val == 2);
  assert(got->next->next->val == 3);
  assert(got->next->next->next == nullptr);
  DeleteListNode(node);
  DeleteListNode(got);
}
