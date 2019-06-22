#include <cmath>
#include <vector>

namespace LeetCode {

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<TreeNode*> CreateTreeNodeVector(const std::vector<int> &vec);

void DeleteTreeNodeVector(std::vector<TreeNode*> &vec);

TreeNode* CreateTreeNode(std::vector<TreeNode*> &vec);


} // namespace LeetCode
