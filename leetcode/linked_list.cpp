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

void DeleteListNode(ListNode* node) {
  while (node) {
    ListNode* next = node->next;
    delete node;
    node = next;
  }
}

} // namespace LeetCode
