#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    queue<pair<TreeNode*, int>> q;
    if (root) {
      q.push({root, 1});
    }
    size_t max_depth = 0;
    while (!q.empty()) {
      pair<TreeNode*, int> element = q.front();
      TreeNode* node = element.first;
      int depth = element.second;
      q.pop();
      if (depth > max_depth) {
        max_depth = depth;
        ret.resize(max_depth);
        ret[ret.size()-1] = node->val;
      } else {
        ret[ret.size()-1] = node->val;
      }
      if (node->left) {
        q.push({node->left, depth + 1});
      }
      if (node->right) {
        q.push({node->right, depth + 1});
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  vector<int> expected;

  root = CreateTreeNode("1 2 3 # 5 # 4"), expected = {1, 3, 4};
  EXPECT_EQ(expected, sol.rightSideView(root));
  DeleteTreeNode(root);

  root = nullptr, expected = {};
  EXPECT_EQ(expected, sol.rightSideView(root));

  exit(EXIT_SUCCESS);
}
