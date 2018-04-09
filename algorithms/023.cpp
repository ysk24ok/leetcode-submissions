#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int interval = 1;
    while (interval < lists.size()) {
      for (int i = 0; i < lists.size() - interval; i += interval * 2) {
        lists[i] = merge2Lists(lists[i], lists[i+interval]);
      }
      interval *= 2;
    }
    return lists.size() > 0 ? lists[0] : NULL;
  }

  ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* last = head;
    while (l1 != NULL || l2 != NULL) {
      ListNode* n = NULL;
      if (l1 == NULL) {
        n = new ListNode(l2->val);
        l2 = l2->next;
      } else if (l2 == NULL) {
        n = new ListNode(l1->val);
        l1 = l1->next;
      } else if (l1->val <= l2->val) {
        n = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        n = new ListNode(l2->val);
        l2 = l2->next;
      }
      last->next = n;
      last = n;
    }
    return head->next;
  }

  void show(ListNode* head) {
    while (head != NULL) {
      cout << "  val: " << head->val << endl;
      head = head->next;
    }
  }
};

int main() {
  Solution* sol = new Solution();
  // l1: 6 8
  // l2: 3 3
  // l3: 10
  ListNode* l1 = new ListNode(6);
  l1->next = new ListNode(8);
  ListNode* l2 = new ListNode(3);
  l2->next = new ListNode(3);
  ListNode* l3 = new ListNode(10);
  vector<ListNode*> v1{l1, l2, l3};
  ListNode* got1 = sol->mergeKLists(v1);
  assert(got1->val == 3);
  assert(got1->next->val == 3);
  assert(got1->next->next->val == 6);
  assert(got1->next->next->next->val == 8);
  assert(got1->next->next->next->next->val == 10);
  assert(got1->next->next->next->next->next == NULL);

  // empty vector
  vector<ListNode*> v2;
  ListNode* got2 = sol->mergeKLists(v2);
  assert(got2 == NULL);

  // all elements is empty
  vector<ListNode*> v3{NULL, NULL, NULL};
  ListNode* got3 = sol->mergeKLists(v3);
  assert(got3 == NULL);
}
