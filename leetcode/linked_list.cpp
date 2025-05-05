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
    if (count > 0 && nodes_deleted == count) { break; }
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

void CreateTwoListNodesWithIntersection(
  const std::vector<int>& vecA,
  const std::vector<int>& vecB,
  size_t skipA,
  size_t skipB,
  ListNode* heads[]
) {
  heads[0] = new ListNode(vecA[0]);
  ListNode* nodeA = heads[0];
  for (size_t idxA = 1; idxA < skipA; idxA++) {
    nodeA->next = new ListNode(vecA[idxA]);
    nodeA = nodeA->next;
  }

  heads[1] = new ListNode(vecB[0]);
  ListNode* nodeB = heads[1];
  for (size_t idxB = 1; idxB < skipB; idxB++) {
    nodeB->next = new ListNode(vecB[idxB]);
    nodeB = nodeB->next;
  }

  for (size_t idxA = skipA; idxA < vecA.size(); idxA++) {
    ListNode* next = new ListNode(vecA[idxA]);
    nodeA->next = next;
    nodeB->next = next;
    nodeA = nodeA->next;
    nodeB = nodeB->next;
  }
}

void DeleteTwoListNodesWithIntersection(ListNode* heads[], size_t skipA, size_t skipB) {
  ListNode* nodeA = heads[0];
  for (size_t idxA = 0; idxA < skipA; idxA++) {
    ListNode* next = nodeA->next;
    delete nodeA;
    nodeA = next;
  }

  ListNode* nodeB = heads[1];
  for (size_t idxB = 0; idxB < skipB; idxB++) {
    ListNode* next = nodeB->next;
    delete nodeB;
    nodeB = next;
  }

  assert(nodeA == nodeB);
  while (nodeA) {
    ListNode* next = nodeA->next;
    delete nodeA;
    nodeA = next;
  }
}

} // namespace LeetCode
