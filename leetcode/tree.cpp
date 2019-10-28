#include <cmath>
#include <sstream>

#include "tree.hpp"

namespace LeetCode {

namespace {

TreeNode* CreateTreeNodeFromVector(std::vector<TreeNode*> &vec) {
  if (vec.size() == 0) return nullptr;
  int power = 0;
  int total = 1;
  TreeNode* parent;
  for (int idx = 0; idx < vec.size(); idx++) {
    // go to next row
    if (idx >= total) {
      power++;
      total += std::pow(2, power);
    }
    if (idx == 0) {
      continue;
    } else if (idx % 2 == 0) {
      parent = vec[idx / 2 - 1];
      if (parent)
        parent->right = vec[idx];
    } else {
      parent = vec[(idx - 1) / 2];
      if (parent)
        parent->left = vec[idx];
    }
  }
  return vec[0];
}

} // namespace

TreeNode* CreateTreeNode(const std::string& str) {
  if (str.size() == 0) return nullptr;
  std::istringstream iss(str);
  std::vector<TreeNode*> vec;
  std::string s;
  while (true) {
    iss >> s;
    if (s == ";") {
      break;
    } else if (s == "#") {
      vec.push_back(nullptr);
    } else {
      vec.push_back(new TreeNode(std::stoi(s)));
    }
  }
  return CreateTreeNodeFromVector(vec);
}

void DeleteTreeNode(TreeNode* node) {
  if (!node) return;
  DeleteTreeNode(node->left);
  DeleteTreeNode(node->right);
  delete node;
}

} // namespace LeetCode
