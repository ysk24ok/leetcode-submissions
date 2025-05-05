#include <cstdlib>
#include <vector>

namespace LeetCode {

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* CreateListNode(const std::vector<int>& vec);

void DeleteListNode(ListNode* node, size_t count = 0);

void AssertListNodeEqual(ListNode* expected, ListNode* actual);

// Used by 0160
void CreateTwoListNodesWithIntersection(
  const std::vector<int>& vecA,
  const std::vector<int>& vecB,
  size_t skipA,
  size_t skipB,
  ListNode* heads[]
);
void DeleteTwoListNodesWithIntersection(ListNode* heads[], size_t skipA, size_t skipB);

} // namespace LeetCode
