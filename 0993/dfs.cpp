#include <string>

#include "leetcode/assert.hpp"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    // parent, depth
    pair<int, int> pair_x = dfs(root, nullptr, x, 0);
    pair<int, int> pair_y = dfs(root, nullptr, y, 0);
    if (pair_x.first == 0 || pair_y.first == 0) { return false; }
    if (pair_x.first == pair_y.first) { return false; }
    return pair_x.second == pair_y.second;
  }

  pair<int, int> dfs(TreeNode* node, TreeNode* parent, int val, int depth) {
    if (!node) { return {0, 0}; }
    if (node->val == val) {
      if (!parent) { return {0, 0}; }
      return {parent->val, depth};
    }
    pair<int, int> pair_l = dfs(node->left, node, val, depth+1);
    pair<int, int> pair_r = dfs(node->right, node, val, depth+1);
    if (pair_l.first != 0) { return pair_l; }
    else { return pair_r; }
  }
};

int main() {
  Solution sol;
  TreeNode* root = nullptr;
  int x, y;

  root = CreateTreeNode("1 2 3 4");
  x = 4, y = 3;
  ExpectEqual(false, sol.isCousins(root, x, y));

  root = CreateTreeNode("1 2 3 # 4 # 5");
  x = 5, y = 4;
  ExpectEqual(true, sol.isCousins(root, x, y));

  root = CreateTreeNode("1 2 3 # 4");
  x = 2, y = 3;
  ExpectEqual(false, sol.isCousins(root, x, y));

  root = CreateTreeNode("1 2 3 # 4");
  x = 1, y = 3;
  ExpectEqual(false, sol.isCousins(root, x, y));
}
