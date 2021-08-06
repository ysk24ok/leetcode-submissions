#include <gtest/gtest.h>

#include <queue>
#include <vector>

#include "leetcode/n_ary_tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ret;
    if (!root) {
      return ret;
    }
    queue<pair<Node*, size_t>> q;
    q.push({root, 0});
    while (!q.empty()) {
      Node* node = q.front().first;
      size_t depth = q.front().second;
      q.pop();
      if (ret.size() == depth) {
        ret.resize(depth + 1);
      }
      ret[depth].push_back(node->val);
      for (Node* child : node->children) {
        q.push({child, depth + 1});
      }
    }
    return ret;
  }
};

int main() {
  Solution sol;
  Node* root;
  vector<vector<int>> expected;

  root = CreateNode("1 # 3 2 4 # 5 6");
  expected = {{1}, {3, 2, 4}, {5, 6}};
  EXPECT_EQ(expected, sol.levelOrder(root));
  DeleteNode(root);

  root = CreateNode("1 # 2 3 4 5 # # 6 7 # 8 # 9 10 # # 11 # 12 # 13 # # 14");
  expected = {{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}};
  EXPECT_EQ(expected, sol.levelOrder(root));
  DeleteNode(root);

  exit(EXIT_SUCCESS);
}
