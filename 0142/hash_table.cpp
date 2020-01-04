#include <cassert>
#include <iostream>
#include <unordered_map>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* detectCycle(ListNode *head) {
    unordered_map<ListNode*, bool> map;
    ListNode* node = head;
    ListNode* ret = nullptr;
    while (node) {
      auto iter = map.find(node);
      if (iter == map.end()) {
        map[node] = true;
      } else {
        ret = node;
        break;
      }
      node = node->next;
    }
    return ret;
  }
};

void AddListNodes(ListNode* dummy,
                  vector<ListNode*>& nodes,
                  const vector<int>& nums) {
  ListNode* node = dummy;
  for (const auto& num : nums) {
    node->next = new ListNode(num);
    nodes.push_back(node->next);
    node = node->next;
  }
}

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

  nums = {3,2,0,-4};
  nodes = {};
  AddListNodes(dummy, nodes, nums);
  nodes[3]->next = nodes[1];
  assert(dummy->next->val == 3);
  assert(dummy->next->next->val == 2);
  assert(dummy->next->next->next->val == 0);
  assert(dummy->next->next->next->next->val == -4);
  assert(dummy->next->next->next->next->next->val == 2);
  assert(sol.detectCycle(dummy->next));
  DeleteListNode(nodes);

  nums = {1,2};
  nodes = {};
  AddListNodes(dummy, nodes, nums);
  nodes[1]->next = nodes[0];
  assert(dummy->next->val == 1);
  assert(dummy->next->next->val == 2);
  assert(dummy->next->next->next->val == 1);
  assert(sol.detectCycle(dummy->next));
  DeleteListNode(nodes);

  nums = {1};
  nodes = {};
  AddListNodes(dummy, nodes, nums);
  assert(dummy->next->val == 1);
  assert(!sol.detectCycle(dummy->next));
  DeleteListNode(nodes);

  delete dummy;
}
