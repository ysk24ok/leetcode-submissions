#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <string>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ret;
    if (!root) {
      return ret;
    }
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});
    long sum = 0;
    int count = 0;
    int curr_level = 1;
    while (!q.empty()) {
      TreeNode* node = q.front().first;
      int level = q.front().second;
      q.pop();
      if (level != curr_level) {
        ret.push_back(static_cast<double>(sum) / count);
        curr_level = level;
        sum = node->val;
        count = 1;
      } else {
        sum += node->val;
        count++;
      }
      if (node->left) {
        q.push({node->left, level + 1});
      }
      if (node->right) {
        q.push({node->right, level + 1});
      }
    }
    ret.push_back(static_cast<double>(sum) / count);
    return ret;
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  vector<double> expected;

  root = CreateTreeNode("3 9 20 # # 15 7"), expected = {3.0, 14.5, 11.0};
  EXPECT_EQ(expected, sol.averageOfLevels(root));
  DeleteTreeNode(root);

  root = nullptr, expected = {};
  EXPECT_EQ(expected, sol.averageOfLevels(root));

  exit(EXIT_SUCCESS);
}
