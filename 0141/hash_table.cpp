#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool hasCycle(ListNode *head) {
    unordered_map<ListNode*, bool> map;
    ListNode* node = head;
    bool ret = false;
    while (node) {
      auto iter = map.find(node);
      if (iter == map.end()) {
        map[node] = true;
      } else {
        ret = true;
        break;
      }
      node = node->next;
    }
    return ret;
  }
};

void DeleteListNode(vector<ListNode*> nodes) {
  for (auto& node : nodes) {
    delete node;
  }
}

int main() {
  Solution sol;
  ListNode* head;
  bool expected;

  head = CreateListNode({3, 2, 0, -4}), expected = true;
  head->next->next->next->next = head->next;
  EXPECT_EQ(expected, sol.hasCycle(head));
  head->next->next->next->next = nullptr;
  DeleteListNode(head);

  head = CreateListNode({1, 2}), expected = true;
  head->next->next = head;
  EXPECT_EQ(expected, sol.hasCycle(head));
  head->next->next = nullptr;
  DeleteListNode(head);

  head = CreateListNode({1}), expected = false;
  EXPECT_EQ(expected, sol.hasCycle(head));
  DeleteListNode(head);

  exit(EXIT_SUCCESS);
}
