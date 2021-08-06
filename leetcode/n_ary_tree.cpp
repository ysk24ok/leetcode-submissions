#include <queue>
#include <sstream>

#include "n_ary_tree.hpp"

namespace LeetCode {

Node* CreateNode(const std::string& str) {
  std::istringstream iss(str);
  std::string s;
  if (!(iss >> s)) {
    return nullptr;
  }
  std::queue<Node*> q;
  Node* root = new Node(std::stoi(s));
  q.push(root);
  iss >> s;
  while (!q.empty()) {
    Node* parent = q.front();
    q.pop();
    while (iss >> s && s != "#") {
      Node* node = new Node(std::stoi(s));
      parent->children.push_back(node);
      q.push(node);
    }
  }
  return root;
}

void DeleteNode(Node* node) {
  if (!node) { return; }
  for (Node* child : node->children) {
    DeleteNode(child);
  }
  delete node;
}

}  // namespace LeetCode