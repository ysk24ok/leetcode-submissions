#include <gtest/gtest.h>

#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

Node* CreateNode(vector<int> values) {
  Node dummy(0);
  Node* prev = &dummy;
  for (const int& value : values) {
    prev->next = new Node(value);
    prev = prev->next;
  }
  return dummy.next;
}

void DeleteNode(Node* node) {
  while (node) {
    Node* next = node->next;
    delete node;
    node = next;
  }
}

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> original2copy;
    Node dummy(0);
    Node* prev = &dummy;
    while (head) {
      Node* new_head = nullptr;
      if (original2copy.find(head) == original2copy.end()) {
        new_head = new Node(head->val);
        original2copy[head] = new_head;
      } else {
        new_head = original2copy[head];
      }
      if (head->random) {
        Node* new_random = nullptr;
        if (original2copy.find(head->random) == original2copy.end()) {
          new_random = new Node(head->random->val);
          original2copy[head->random] = new_random;
        } else {
          new_random = original2copy[head->random];
        }
        new_head->random = new_random;
      }
      prev->next = new_head;
      head = head->next;
      prev = prev->next;
    }
    return dummy.next;
  }
};

int main() {
  Solution sol;
  Node *head, *got;
  vector<int> values;

  values = {7, 13, 11, 10, 1};
  head = CreateNode(values);
  head->next->random = head;
  head->next->next->random = head->next->next->next->next;
  head->next->next->next->random = head->next->next;
  head->next->next->next->next->random = head;
  got = sol.copyRandomList(head);
  EXPECT_EQ(values[0], got->val);
  EXPECT_EQ(values[1], got->next->val);
  EXPECT_EQ(values[2], got->next->next->val);
  EXPECT_EQ(values[3], got->next->next->next->val);
  EXPECT_EQ(values[4], got->next->next->next->next->val);
  EXPECT_EQ(nullptr, got->next->next->next->next->next);
  EXPECT_EQ(nullptr, got->random);
  EXPECT_EQ(got, got->next->random);
  EXPECT_EQ(got->next->next->next->next, got->next->next->random);
  EXPECT_EQ(got->next->next, got->next->next->next->random);
  EXPECT_EQ(got, got->next->next->next->next->random);
  DeleteNode(head);
  DeleteNode(got);

  values = {1, 2};
  head = CreateNode(values);
  head->random = head->next;
  head->next->random = head->next;
  got = sol.copyRandomList(head);
  EXPECT_EQ(values[0], got->val);
  EXPECT_EQ(values[1], got->next->val);
  EXPECT_EQ(nullptr, got->next->next);
  EXPECT_EQ(got->next, got->random);
  EXPECT_EQ(got->next, got->next->random);
  DeleteNode(head);
  DeleteNode(got);

  values = {3, 3, 3};
  head = CreateNode(values);
  head->next->random = head;
  got = sol.copyRandomList(head);
  EXPECT_EQ(values[0], got->val);
  EXPECT_EQ(values[1], got->next->val);
  EXPECT_EQ(values[2], got->next->next->val);
  EXPECT_EQ(nullptr, got->next->next->next);
  EXPECT_EQ(got, got->next->random);
  DeleteNode(head);
  DeleteNode(got);

  EXPECT_EQ(nullptr, sol.copyRandomList(nullptr));

  exit(EXIT_SUCCESS);
}
