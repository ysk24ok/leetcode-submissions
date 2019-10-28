#include <cassert>
#include <sstream>
#include <string>

#include "../leetcode/tree.hpp"

using namespace std;
using namespace LeetCode;

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream oss;
    serDfs(root, oss);
    return oss.str();
  }

  void serDfs(TreeNode* node, ostringstream& oss) {
    if (node != NULL) {
      oss << node->val << " ";
      serDfs(node->left, oss);
      serDfs(node->right, oss);
    } else {
      oss << "# ";
    }
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream iss(data);
    return deserDfs(iss);
  }

  TreeNode* deserDfs(istringstream& iss) {
    string s;
    iss >> s;
    if (s == "#") {
      return NULL;
    }
    TreeNode* node = new TreeNode(stoi(s));
    node->left = deserDfs(iss);
    node->right = deserDfs(iss);
    return node;
  }
};

int main() {
  Codec codec;

  string s = "1 2 3 # # 4 5 ;";
  TreeNode* root = CreateTreeNode(s);

  TreeNode* got = codec.deserialize(codec.serialize(root));
  assert(got->val == 1);
  assert(got->left->val == 2);
  assert(got->right->val == 3);
  assert(got->left->left == NULL);
  assert(got->left->right == NULL);
  assert(got->right->left->val == 4);
  assert(got->right->right->val == 5);
  DeleteTreeNode(got);
  DeleteTreeNode(root);
}
