// depth first search

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) {
      return NULL;
    }
    if (map_.find(node->label) != map_.end()) {
      return map_.at(node->label);
    }
    UndirectedGraphNode * clonedNode = new UndirectedGraphNode(node->label);
    map_.insert(std::make_pair(node->label, clonedNode));
    for (auto* n : node->neighbors) {
      clonedNode->neighbors.push_back(cloneGraph(n));
    }
    return clonedNode;
  }
 private:
  unordered_map<int, UndirectedGraphNode*> map_;
};

int main() {
  Solution * sol = new Solution();
  UndirectedGraphNode *node;
  UndirectedGraphNode *clonedNode;

  UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
  UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
  UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
  node0->neighbors.push_back(node1);
  node0->neighbors.push_back(node2);
  node1->neighbors.push_back(node0);
  node1->neighbors.push_back(node2);
  node2->neighbors.push_back(node0);
  node2->neighbors.push_back(node1);
  clonedNode = sol->cloneGraph(node);
  delete sol;
}
