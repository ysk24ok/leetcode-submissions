#include <gtest/gtest.h>

#include <cstdlib>
#include <stack>
#include <string>

#include "leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    traversal(root);
  }

  int next() {
    TreeNode* node = st.top();
    st.pop();
    return node->val;
  }

  bool hasNext() {
    return !st.empty();
  }

 private:
  void traversal(TreeNode* node) {
    if (!node) { return; }
    if (node->right) {
      traversal(node->right);
    }
    st.push(node);
    if (node->left) {
      traversal(node->left);
    }
  }

  stack<TreeNode*> st;
};

int main() {
  string s;
  TreeNode* root;

  s = "7 3 15 # # 9 20";
  root = CreateTreeNode(s);
  BSTIterator iterator(root);
  EXPECT_EQ(3, iterator.next());
  EXPECT_EQ(7, iterator.next());
  EXPECT_EQ(true, iterator.hasNext());
  EXPECT_EQ(9, iterator.next());
  EXPECT_EQ(true, iterator.hasNext());
  EXPECT_EQ(15, iterator.next());
  EXPECT_EQ(true, iterator.hasNext());
  EXPECT_EQ(20, iterator.next());
  EXPECT_EQ(false, iterator.hasNext());
  DeleteTreeNode(root);

  exit(EXIT_SUCCESS);
}
