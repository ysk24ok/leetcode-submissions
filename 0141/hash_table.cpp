#include <cassert>
#include <iostream>
#include <unordered_map>

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
  vector<int> nums;
  vector<ListNode*> nodes;
  ListNode* dummy = new ListNode(0);
  ListNode* node;

  node = dummy;
  nums = {3,2,0,-4};
  nodes = {};
  for (auto& num : nums) {
    node->next = new ListNode(num);
    nodes.push_back(node->next);
    node = node->next;
  }
  node->next = nodes[1];
  assert(dummy->next->val == 3);
  assert(dummy->next->next->val == 2);
  assert(dummy->next->next->next->val == 0);
  assert(dummy->next->next->next->next->val == -4);
  assert(dummy->next->next->next->next->next->val == 2);
  assert(sol.hasCycle(dummy->next));
  DeleteListNode(nodes);

  node = dummy;
  nums = {1,2};
  nodes = {};
  for (auto& num : nums) {
    node->next = new ListNode(num);
    nodes.push_back(node->next);
    node = node->next;
  }
  node->next = nodes[0];
  assert(dummy->next->val == 1);
  assert(dummy->next->next->val == 2);
  assert(dummy->next->next->next->val == 1);
  assert(sol.hasCycle(dummy->next));
  DeleteListNode(nodes);

  node = dummy;
  nums = {1};
  nodes = {};
  for (auto& num : nums) {
    node->next = new ListNode(num);
    nodes.push_back(node->next);
    node = node->next;
  }
  assert(dummy->next->val == 1);
  assert(!sol.hasCycle(dummy->next));
  DeleteListNode(nodes);

  delete dummy;
}
