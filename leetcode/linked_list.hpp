#include <vector>

namespace LeetCode {

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* CreateListNode(const std::vector<int>& vec);

void DeleteListNode(ListNode* node);

} // namespace LeetCode
