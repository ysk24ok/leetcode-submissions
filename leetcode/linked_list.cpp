#include <cassert>

#include "linked_list.hpp"

namespace LeetCode {

ListNode* CreateListNode(const std::vector<int>& vec) {
  if (vec.size() == 0)
    return nullptr;
  ListNode* head = new ListNode(vec[0]);
  if (vec.size() == 1)
    return head;
  ListNode* prev = head;
  for (int i = 1; i < vec.size(); i++) {
    ListNode* node = new ListNode(vec[i]);
    prev->next = node;
    prev = node;
  }
  return head;
}

void DeleteListNode(ListNode* node, size_t count) {
  size_t nodes_deleted = 0;
  while (node) {
    // deal with cycle
    if (count >= 0 && nodes_deleted == count) { break; }
    ListNode* next = node->next;
    delete node;
    node = next;
    nodes_deleted++;
  }
}

void AssertListNodeEqual(ListNode* expected, ListNode* actual) {
  while (expected && actual) {
    assert(expected->val == actual->val);
    expected = expected->next;
    actual = actual->next;
  }
  assert(!expected && !actual);
}

} // namespace LeetCode
