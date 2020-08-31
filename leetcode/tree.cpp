#include <queue>
#include <sstream>

#include "tree.hpp"

namespace LeetCode {

TreeNode* CreateTreeNode(const std::string& str) {
  std::istringstream iss(str);
  std::string s;
  if (!(iss >> s)) {
    return nullptr;
  }
  TreeNode* root = new TreeNode(std::stoi(s));
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    if (iss >> s && s != "#") {
      node->left = new TreeNode(std::stoi(s));
      q.push(node->left);
    }
    if (iss >> s && s != "#") {
      node->right = new TreeNode(std::stoi(s));
      q.push(node->right);
    }
  }
  return root;
}

void DeleteTreeNode(TreeNode* node) {
  if (!node) return;
  DeleteTreeNode(node->left);
  DeleteTreeNode(node->right);
  delete node;
}

} // namespace LeetCode
