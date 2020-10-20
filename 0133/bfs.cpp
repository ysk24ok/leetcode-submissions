#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {
      val = 0;
      neighbors = vector<Node*>();
  }

  Node(int _val) {
      val = _val;
      neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
      val = _val;
      neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) { return nullptr; }
    unordered_map<int, Node*> visited;
    Node* cloned_node = new Node(node->val);
    Node* cloned_head = cloned_node;
    visited[node->val] = cloned_node;
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
      node = q.front();
      q.pop();
      cloned_node = visited[node->val];
      for (Node* neighbor : node->neighbors) {
        Node* cloned_neighbor;
        if (visited.find(neighbor->val) == visited.end()) {
          cloned_neighbor = new Node(neighbor->val);
          visited[neighbor->val] = cloned_neighbor;
          q.push(neighbor);
        } else {
          cloned_neighbor = visited[neighbor->val];
        }
        cloned_node->neighbors.push_back(cloned_neighbor);
      }
    }
    return cloned_head;
  }
};

void DeleteNode(Node* node) {
  unordered_map<int, Node*> visited;
  queue<Node*> q;
  while (!q.empty()) {
    node = q.front();
    q.pop();
    for (Node* neighbor : node->neighbors) {
      if (visited.find(neighbor->val) != visited.end()) { continue; }
      visited[neighbor->val] = neighbor;
      q.push(neighbor);
    }
    delete node;
  }
}

int main() {
  Solution sol;
  Node* got;

  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  node1->neighbors.push_back(node2);
  node1->neighbors.push_back(node4);
  node2->neighbors.push_back(node1);
  node2->neighbors.push_back(node3);
  node3->neighbors.push_back(node2);
  node3->neighbors.push_back(node4);
  node4->neighbors.push_back(node1);
  node4->neighbors.push_back(node3);
  got = sol.cloneGraph(node1);
  EXPECT_EQ(node1->val, got->val);
  EXPECT_EQ(node2->val, got->neighbors[0]->val);
  EXPECT_EQ(node4->val, got->neighbors[1]->val);
  EXPECT_EQ(node1->val, got->neighbors[0]->neighbors[0]->val);
  EXPECT_EQ(node3->val, got->neighbors[0]->neighbors[1]->val);
  EXPECT_EQ(node1->val, got->neighbors[1]->neighbors[0]->val);
  EXPECT_EQ(node3->val, got->neighbors[1]->neighbors[1]->val);
  DeleteNode(node1);
  DeleteNode(got);

  exit(EXIT_SUCCESS);
}
