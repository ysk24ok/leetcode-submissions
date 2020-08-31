#include <string>
#include <vector>

namespace LeetCode {

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* CreateTreeNode(const std::string& str);

void DeleteTreeNode(TreeNode* node);

}  // namespace LeetCode
