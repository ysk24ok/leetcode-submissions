#include <vector>

#include "leetcode/assert.hpp"
#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    size_t n = preorder.size();
    if (n == 0) { return nullptr; }
    TreeNode* root = new TreeNode(preorder[0]);
    for (size_t i = 1; i < preorder.size(); ++i) {
      addNode(preorder, root, i);
    }
    return root;
  }

  void addNode(const vector<int>& preorder, TreeNode* parent, size_t i) {
    if (preorder[i] > parent->val) {
      if (!parent->right) {
        parent->right = new TreeNode(preorder[i]);
      } else {
        addNode(preorder, parent->right, i);
      }
    } else {
      if (!parent->left) {
        parent->left = new TreeNode(preorder[i]);
      } else {
        addNode(preorder, parent->left, i);
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> preorder;
  TreeNode* got;

  preorder = {8,5,1,7,10,12};
  got = sol.bstFromPreorder(preorder);
  ExpectEqual(8, got->val);
  ExpectEqual(5, got->left->val);
  ExpectEqual(1, got->left->left->val);
  ExpectEqual(7, got->left->right->val);
  ExpectEqual(10, got->right->val);
  ExpectEqual(12, got->right->right->val);
  DeleteTreeNode(got);

  preorder = {};
  ExpectEqual(true, !sol.bstFromPreorder(preorder));
}
