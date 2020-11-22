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

} // namespace LeetCode
