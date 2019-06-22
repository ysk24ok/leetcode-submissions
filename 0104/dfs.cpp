#include <cassert>
#include <vector>

#include "../leetcode/tree.hpp"

using namespace LeetCode;

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    return dfs(root);
  }

  int dfs(TreeNode* node) {
    if (node == NULL) {
      return 0;
    }
    int left_depth = dfs(node->left);
    int right_depth = dfs(node->right);
    return std::max(left_depth, right_depth) + 1;
  }
};

int main() {
  Solution* sol = new Solution();
  std::vector<int> vec;
  std::vector<TreeNode*> node_vec;
  TreeNode* node;

  vec = {3, 9, 20, NULL, NULL, 15, 7};
  node_vec = CreateTreeNodeVector(vec);
  node = CreateTreeNode(node_vec);
  assert(sol->maxDepth(node) == 3);
  DeleteTreeNodeVector(node_vec);

  node = new TreeNode(0);
  assert(sol->maxDepth(node) == 1);
  delete node;

  delete sol;
}
