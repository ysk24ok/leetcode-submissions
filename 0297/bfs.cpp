#include <cassert>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream oss;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node != NULL) {
        oss << node->val << " ";
        q.push(node->left);
        q.push(node->right);
      } else {
        oss << "# ";
      }
    }
    return oss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream iss(data);
    if (!iss.rdbuf()->in_avail())
      return NULL;
    queue<TreeNode*> q;
    string s;
    iss >> s;
    if (s == "#")
      return NULL;
    TreeNode* root = new TreeNode(stoi(s));
    TreeNode* parent;
    TreeNode* node;
    q.push(root);
    while (!q.empty()) {
      parent = q.front();
      q.pop();
      iss >> s;
      if (s != "#") {
        node = new TreeNode(stoi(s));
        parent->left = node;
        q.push(node);
      }
      iss >> s;
      if (s != "#") {
        node = new TreeNode(stoi(s));
        parent->right = node;
        q.push(node);
      }
    }
    return root;
  }
};

int main() {
  Codec codec;
  string s;
  TreeNode* root;
  TreeNode* got;

  //      1
  //     / \
  //    2   3
  //       / \
  //      4   5
  s = "1 2 3 # # 4 5";
  root = CreateTreeNode(s);
  got = codec.deserialize(codec.serialize(root));
  assert(got->val == 1);
  assert(got->left->val == 2);
  assert(got->right->val == 3);
  assert(got->left->left == NULL);
  assert(got->left->right == NULL);
  assert(got->right->left->val == 4);
  assert(got->right->right->val == 5);
  DeleteTreeNode(got);
  DeleteTreeNode(root);

  //      5
  //     / \
  //    2   3
  //       / \
  //      2   4
  //     / \
  //    3   1
  s = "5 2 3 # # 2 4 3 1";
  root = CreateTreeNode(s);
  got = codec.deserialize(codec.serialize(root));
  assert(got->val == 5);
  assert(got->left->val == 2);
  assert(got->right->val == 3);
  assert(got->left->left == NULL);
  assert(got->left->right == NULL);
  assert(got->right->left->val == 2);
  assert(got->right->right->val == 4);
  DeleteTreeNode(got);
  DeleteTreeNode(root);

  got = codec.deserialize(codec.serialize(nullptr));
  assert(got == nullptr);
}
