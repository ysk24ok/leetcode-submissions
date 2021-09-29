#include <gtest/gtest.h>

#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int num_nodes = 0;
    ListNode* node = head;
    while (node) {
      num_nodes++;
      node = node->next;
    }

    vector<ListNode*> ret(k, nullptr);
    int residual = num_nodes % k;
    int num_nodes_per_part = num_nodes / k;
    size_t part_idx = 0;
    node = head;
    ListNode* prev;
    while (node) {
      int num_nodes_of_this_part = num_nodes_per_part;
      if (residual-- > 0) {
        num_nodes_of_this_part++;
      }
      ret[part_idx++] = node;
      while (num_nodes_of_this_part > 0) {
        prev = node;
        node = node->next;
        num_nodes_of_this_part--;
      }
      prev->next = nullptr;
    }
    return ret;
  }
};

int main() {
  Solution sol;
  ListNode* head;
  int k;
  vector<ListNode*> actual;

  head = CreateListNode({1, 2, 3}), k = 5;
  actual = sol.splitListToParts(head, k);
  EXPECT_EQ(actual.size(), k);
  EXPECT_EQ(actual[0]->val, 1);
  EXPECT_EQ(actual[0]->next, nullptr);
  EXPECT_EQ(actual[1]->val, 2);
  EXPECT_EQ(actual[1]->next, nullptr);
  EXPECT_EQ(actual[2]->val, 3);
  EXPECT_EQ(actual[2]->next, nullptr);
  EXPECT_EQ(actual[3], nullptr);
  EXPECT_EQ(actual[4], nullptr);
  for (const auto& node : actual) {
    DeleteListNode(node);
  }

  head = CreateListNode({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}), k = 3;
  actual = sol.splitListToParts(head, k);
  EXPECT_EQ(actual.size(), k);
  EXPECT_EQ(actual[0]->val, 1);
  EXPECT_EQ(actual[0]->next->val, 2);
  EXPECT_EQ(actual[0]->next->next->val, 3);
  EXPECT_EQ(actual[0]->next->next->next->val, 4);
  EXPECT_EQ(actual[0]->next->next->next->next, nullptr);
  EXPECT_EQ(actual[1]->val, 5);
  EXPECT_EQ(actual[1]->next->val, 6);
  EXPECT_EQ(actual[1]->next->next->val, 7);
  EXPECT_EQ(actual[1]->next->next->next, nullptr);
  EXPECT_EQ(actual[2]->val, 8);
  EXPECT_EQ(actual[2]->next->val, 9);
  EXPECT_EQ(actual[2]->next->next->val, 10);
  EXPECT_EQ(actual[2]->next->next->next, nullptr);
  for (const auto& node : actual) {
    DeleteListNode(node);
  }

  exit(EXIT_SUCCESS);
}
