#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) { return nullptr; }
    queue<pair<Node*, int>> q;
    Node* left_node = nullptr;
    int left_level = 0;
    q.push({root, 1});
    while (!q.empty()) {
      const pair<Node*, int>& p = q.front();
      Node* node = p.first;
      int level = p.second;
      q.pop();
      if (level == left_level) {
        left_node->next = node;
      }
      if (node->left) {
        q.push({node->left, level+1});
      }
      if (node->right) {
        q.push({node->right, level+1});
      }
      left_node = node;
      left_level = level;
    }
    return root;
  }
};

void DeleteNode(Node* node) {
  if (!node) { return; }
  DeleteNode(node->left);
  DeleteNode(node->right);
  delete node;
}

int main() {
  Solution sol;
  Node *root, *got;

  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(7);
  got = sol.connect(root);
  EXPECT_FALSE(root->next);
  EXPECT_EQ(3, root->left->next->val);
  EXPECT_FALSE(root->left->next->next);
  EXPECT_EQ(5, root->left->left->next->val);
  EXPECT_EQ(7, root->left->left->next->next->val);
  EXPECT_FALSE(root->left->left->next->next->next);
  DeleteNode(root);

  EXPECT_FALSE(sol.connect(nullptr));

  exit(EXIT_SUCCESS);
}
