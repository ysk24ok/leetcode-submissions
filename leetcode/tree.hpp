#include <string>
#include <vector>

namespace LeetCode {

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* CreateTreeNode(const std::string& str);

void DeleteTreeNode(TreeNode* node);

} // namespace LeetCode
