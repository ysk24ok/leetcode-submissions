#include <vector>

#include "leetcode/assert.hpp"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  bool isValidSequence(TreeNode* root, vector<int>& arr) {
    return dfs(root, arr, 0);
  }

  bool dfs(TreeNode* node, const vector<int>& arr, size_t idx) {
    // leaf
    if (!node->left && !node->right && idx == arr.size()-1 && node->val == arr[idx]) { return true; }
    if (idx >= arr.size()) { return false; }
    if (node->val != arr[idx]) { return false; }
    bool ret = false;
    if (node->left) { ret |= dfs(node->left, arr, idx+1); }
    if (node->right) { ret |= dfs(node->right, arr, idx+1); }
    return ret;
  }
};

int main() {
  Solution sol;
  TreeNode* root = nullptr;
  vector<int> arr;

  //          0
  //        /   \
  //      1       0
  //    /   \    /
  //   0     1  0
  //    \   / \
  //     1 0   0
  root = CreateTreeNode("0 1 0 0 1 0 # # 1 0 0");
  arr = {0,1,0,1};
  ExpectEqual(true, sol.isValidSequence(root, arr));
  arr = {0,0,0};
  ExpectEqual(true, sol.isValidSequence(root, arr));
  arr = {0,1,1,0};
  ExpectEqual(true, sol.isValidSequence(root, arr));
  arr = {0,1,1,1};
  ExpectEqual(false, sol.isValidSequence(root, arr));
  arr = {0,0,1};
  ExpectEqual(false, sol.isValidSequence(root, arr));
  arr = {0,1,1};
  ExpectEqual(false, sol.isValidSequence(root, arr));
  arr = {0,0};
  ExpectEqual(false, sol.isValidSequence(root, arr));
  DeleteTreeNode(root);

  //       8
  //      /
  //     3
  //    / \
  //   2   1
  //  / \
  // 5   4
  root = CreateTreeNode("8 3 # 2 1 5 4");
  arr = {8,3,1};
  ExpectEqual(true, sol.isValidSequence(root, arr));
  arr = {8,3};
  ExpectEqual(false, sol.isValidSequence(root, arr));
  arr = {8,3,2};
  ExpectEqual(false, sol.isValidSequence(root, arr));
  arr = {8,3,2,5};
  ExpectEqual(true, sol.isValidSequence(root, arr));
  arr = {8,3,2,4};
  ExpectEqual(true, sol.isValidSequence(root, arr));
  arr = {8};
  ExpectEqual(false, sol.isValidSequence(root, arr));
  DeleteTreeNode(root);
}
