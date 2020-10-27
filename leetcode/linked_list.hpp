#include <vector>

namespace LeetCode {

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* CreateListNode(const std::vector<int>& vec);

void DeleteListNode(ListNode* node, size_t count = 0);

void AssertListNodeEqual(ListNode* expected, ListNode* actual);

} // namespace LeetCode
