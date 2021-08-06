#include <string>
#include <vector>

namespace LeetCode {

// Definition for a Node.
class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

Node* CreateNode(const std::string& str);

void DeleteNode(Node* node);

}  // namespace LeetCode