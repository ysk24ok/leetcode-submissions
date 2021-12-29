#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

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
    Node* parent = root;
    while (parent->left) {
      Node* next_parent = parent->left;
      while (parent) {
        parent->left->next = parent->right;
        if (parent->next) {
          parent->right->next = parent->next->left;
        }
        parent = parent->next;
      }
      parent = next_parent;
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
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  got = sol.connect(root);
  EXPECT_FALSE(root->next);
  EXPECT_EQ(3, root->left->next->val);
  EXPECT_FALSE(root->left->next->next);
  EXPECT_EQ(5, root->left->left->next->val);
  EXPECT_EQ(6, root->left->left->next->next->val);
  EXPECT_EQ(7, root->left->left->next->next->next->val);
  EXPECT_FALSE(root->left->left->next->next->next->next);
  DeleteNode(root);

  EXPECT_FALSE(sol.connect(nullptr));

  exit(EXIT_SUCCESS);
}
