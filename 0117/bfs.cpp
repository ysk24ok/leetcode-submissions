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
    queue<pair<Node*, int>> q;
    Node* prev_node = nullptr;
    int row_of_prev_node = 0;
    q.push({root, 0});
    while (!q.empty()) {
      pair<Node*, int> elem = q.front();
      q.pop();
      Node* node = elem.first;
      const int& row = elem.second;
      if (prev_node && row_of_prev_node == row) {
        prev_node->next = node;
      }
      if (node->left) {
        q.push({node->left, row + 1});
      }
      if (node->right) {
        q.push({node->right, row + 1});
      }
      prev_node = node;
      row_of_prev_node = row;
    }
    return root;
  }
};

void DeleteNode(Node* node) {
  if (!node) { return ; }
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
