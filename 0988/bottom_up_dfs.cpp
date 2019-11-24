#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "../leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

// This bottom-up approch does not work with some cases
// such as [25,1,null,0,0,1,null,null,null,0]
// See https://leetcode.com/problems/smallest-string-starting-from-leaf/discuss/244205/Divide-and-conquer-technique-doesn't-work-for-this-problem
class Solution {
 public:
  string smallestFromLeaf(TreeNode* root) {
    return dfs(root);
  }

  string dfs(TreeNode* node) {
    if (!node) return "";
    string lstr = dfs(node->left);
    string rstr = dfs(node->right);
    char c = getChar(node->val);
    if (lstr.size() == 0 && rstr.size() == 0) {
      return {c};
    } else if (lstr.size() == 0 && rstr.size() > 0) {
      return rstr.append(1, c);
    } else if (lstr.size() > 0 && rstr.size() == 0) {
      return lstr.append(1, c);
    }
    string llstr = lstr.append(1, c);
    string rrstr = rstr.append(1, c);
    return (compareLexicographically(llstr, rrstr)) ? llstr : rrstr;
  }

  char getChar(int i) {
    int base = int('a');
    return char(base+i);
  }

  bool compareLexicographically(const string& s1, const string& s2) {
    cout << s1 << ", " << s2 << endl;
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

  s = "0 1 2 3 4 3 4 ;";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "dba");

  s = "25 1 3 1 3 0 2 ;";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "adz");

  s = "2 2 1 # 1 0 # 0 ;";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "abc");

  s = "1 ;";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "b");

  assert(sol.compareLexicographically("be", "bae") == false);

  //   4
  //  0 1
  // 1
  s = "4 0 1 1 ;";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "bae");

  //     25
  //    1
  //   0 0
  //  1
  // 0
  s = "25 1 # 0 0 # # 1 # # # # # # # 0 ;";
  node = CreateTreeNode(s);
  assert(sol.smallestFromLeaf(node) == "ababz");
}
