#include "tree.hpp"

namespace LeetCode {

std::vector<TreeNode*> CreateTreeNodeVector(const std::vector<int> &vec) {
  std::vector<TreeNode*> new_vec(vec.size());
  for (int idx = 0; idx < vec.size(); idx++) {
    new_vec[idx] = new TreeNode(vec[idx]);
  }
  return new_vec;
}

void DeleteTreeNodeVector(std::vector<TreeNode*> &vec) {
  for (TreeNode* node : vec) {
    delete node;
  }
}

TreeNode* CreateTreeNode(std::vector<TreeNode*> &vec) {
  int power = 0;
  int total = 1;
  TreeNode* parent;
  for (int idx = 0; idx < vec.size(); idx++) {
    // go to next row
    if (idx >= total) {
      power++;
      total += std::pow(2, power);
    }
    if (vec[idx]->val == NULL) {
      continue;
    }
    if (idx == 0) {
      continue;
    } else if (idx % 2 == 0) {
      parent = vec[idx / 2 - 1];
      parent->right = vec[idx];
    } else {
      parent = vec[(idx - 1) / 2];
      parent->left = vec[idx];
    }
  }
  return (vec.size() > 0) ? vec[0] : 0;
}

} // namespace LeetCode
