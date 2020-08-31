#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  string smallestFromLeaf(TreeNode* root) {
    return dfs(root, "");
  }

  string dfs(TreeNode* node, const string& suffix) {
    if (!node) return "";
    string new_suffix = string(1, getChar(node->val)) + suffix;
    string lstr = dfs(node->left, new_suffix);
    string rstr = dfs(node->right, new_suffix);
    if (lstr.size() == 0 && rstr.size() == 0) {
      return new_suffix;
    }
    //cout << "node: " << node->val << ", " << lstr << ", " << rstr << endl;
    return (compareLexicographically(lstr, rstr)) ? lstr : rstr;
  }

  char getChar(int i) {
    int base = int('a');
    return char(base+i);
  }

  // I don't have to use this complex function, just use std::min
  // see https://leetcode.com/problems/smallest-string-starting-from-leaf/discuss/231102/C%2B%2B-3-lines
  bool compareLexicographically(const string& s1, const string& s2) {
    if (s1.size() == 0) return false;
    if (s2.size() == 0) return true;
    size_t size = (s1.size() > s2.size()) ? s2.size() : s1.size();
    for (int i = 0; i < size; i++) {
      if (s1[i] == s2[i]) continue;
      if (int(s1[i]) < int(s2[i])) return true;
      return false;
    }
    return false;
  }
};

int main() {
  Solution sol;
  string s;
  TreeNode* node;

  s = "0 1 2 3 4 3 4";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "dba");
  DeleteTreeNode(node);

  s = "25 1 3 1 3 0 2";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "adz");
  DeleteTreeNode(node);

  s = "2 2 1 # 1 0 # 0";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "abc");
  DeleteTreeNode(node);

  s = "1";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "b");
  DeleteTreeNode(node);

  //   4
  //  0 1
  // 1
  s = "4 0 1 1";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "bae");
  DeleteTreeNode(node);

  //     25
  //    1
  //   0 0
  //  1
  // 0
  s = "25 1 # 0 0 1 # # # 0";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "ababz");
  DeleteTreeNode(node);
}
