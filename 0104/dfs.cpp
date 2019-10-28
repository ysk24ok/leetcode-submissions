#include <cassert>
#include <string>

#include "../leetcode/tree.hpp"

using namespace LeetCode;

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    return dfs(root);
  }

  int dfs(TreeNode* node) {
    if (!node) {
      return 0;
    }
    int left_depth = dfs(node->left);
    int right_depth = dfs(node->right);
    return std::max(left_depth, right_depth) + 1;
  }
};

int main() {
  Solution* sol = new Solution();
  std::string s;
  TreeNode* node;
  int got;

  s = "3 9 20 # # 15 7 ;";
  node = CreateTreeNode(s);
  got = sol->maxDepth(node);
  DeleteTreeNode(node);
  assert(got == 3);

  node = new TreeNode(0);
  assert(sol->maxDepth(node) == 1);
  delete node;

  assert(sol->maxDepth(nullptr) == 0);

  delete sol;
}
