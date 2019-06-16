#include <cassert>

/**
* Definition for singly-linked list.
*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode * n1 = l1;
    ListNode * n2 = l2;
    ListNode * leading_node = NULL;
    ListNode * last_node = NULL;
    int moving_up = 0;
    while (n1 != NULL or n2 != NULL) {
      int v1 = 0;
      if (n1 != NULL) {
          v1 = n1->val;
          n1 = n1->next;
      }
      int v2 = 0;
      if (n2 != NULL) {
          v2 = n2->val;
          n2 = n2->next;
      }
      int sum = v1 + v2 + moving_up;
      moving_up = sum / 10;
      ListNode * n = new ListNode(sum % 10);
      if (leading_node != NULL) {
          last_node->next = n;
          last_node = n;
      } else {
          leading_node = n;
          last_node = n;
      }
    }
    if (moving_up != 0) {
      ListNode * n = new ListNode(moving_up);
      last_node->next = n;
    }
    return leading_node;
  }
};

int main() {
  Solution * sol = new Solution();
  // l1: 60
  ListNode * l1 = new ListNode(0);
  l1->next = new ListNode(6);
  // n2: 972
  ListNode * l2 = new ListNode(2);
  l2->next = new ListNode(7);
  l2->next->next = new ListNode(9);
  ListNode * got = sol->addTwoNumbers(l1, l2);
  assert(got->val == 2);
  assert(got->next->val == 3);
  assert(got->next->next->val == 0);
  assert(got->next->next->next->val == 1);

  delete sol;
}
