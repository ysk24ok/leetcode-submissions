#include <cassert>
#include <iostream>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    vector<string> v = dfs(root);
    int sum = 0;
    for (auto s : v) {
      sum += stoi(s);
    }
    return sum;
  }

  vector<string> dfs(TreeNode* node) {
    if (!node) return {};
    string sval = to_string(node->val);
    vector<string> v = dfs(node->left);
    vector<string> v_r = dfs(node->right);
    copy(v_r.begin(), v_r.end(), back_inserter(v));
    if (v.size() > 0) {
      for (auto& s : v) {
        s = sval + s;
      }
    } else {
      v.push_back(sval);
    }
    return v;
  }
};

int main() {
  Solution sol;
  string s;
  TreeNode* node;
  int got;

  s = "1 2 3";
  node = CreateTreeNode(s);
  got = sol.sumNumbers(node);
  DeleteTreeNode(node);
  assert(got == 25);

  s = "4 9 0 5 1";
  node = CreateTreeNode(s);
  got = sol.sumNumbers(node);
  DeleteTreeNode(node);
  assert(got == 1026);

  s = "4 0 9 # # 5 1";
  node = CreateTreeNode(s);
  got = sol.sumNumbers(node);
  DeleteTreeNode(node);
  assert(got == 1026);

  assert(sol.sumNumbers(nullptr) == 0);
}
