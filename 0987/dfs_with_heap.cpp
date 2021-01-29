#include <gtest/gtest.h>

#include <cstdlib>
#include <queue>
#include <map>
#include <string>
#include <vector>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

auto compare = [](const pair<TreeNode*, int>& left,
                  const pair<TreeNode*, int>& right) {
  if (left.second != right.second) {
    return left.second < right.second;
  } else {
    return left.first->val > right.first->val;
  }
};

using Queue = priority_queue<pair<TreeNode*, int>, vector<pair<TreeNode*, int>>, decltype(compare)>;

class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, Queue> nodes_per_x_coordinates;
    dfs(root, 0, 0, nodes_per_x_coordinates);
    vector<vector<int>> ret;
    for (auto& kv : nodes_per_x_coordinates) {
      Queue& queue = kv.second;
      vector<int> nodes;
      nodes.reserve(queue.size());
      while (!queue.empty()) {
        nodes.push_back(queue.top().first->val);
        queue.pop();
      }
      ret.push_back(nodes);
    }
    return ret;
  }

  void dfs(TreeNode* node, int x, int y,
           map<int, Queue>& nodes_per_x_coordinates) {
    if (!node) { return; }
    if (nodes_per_x_coordinates.find(x) == nodes_per_x_coordinates.end()) {
      nodes_per_x_coordinates.emplace(x, compare);
    }
    nodes_per_x_coordinates.at(x).push({node, y});
    dfs(node->left, x - 1, y - 1, nodes_per_x_coordinates);
    dfs(node->right, x + 1, y - 1, nodes_per_x_coordinates);
  }
};

int main() {
  Solution sol;
  TreeNode* root;
  vector<vector<int>> expected;

  root = CreateTreeNode("3 9 20 # # 15 7"), expected = {{9}, {3, 15}, {20}, {7}};
  EXPECT_EQ(expected, sol.verticalTraversal(root));
  DeleteTreeNode(root);

  root = CreateTreeNode("1 2 3 4 5 6 7"), expected = {{4}, {2}, {1, 5, 6}, {3}, {7}};
  EXPECT_EQ(expected, sol.verticalTraversal(root));
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
