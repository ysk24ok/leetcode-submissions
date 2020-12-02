#include <gtest/gtest.h>

#include <cstdlib>
#include <random>
#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

/**
 * time complexity:
 *  Solution(): O(N)
 *  getRandom(): O(N)
 * space complexity: O(1)
 */
class Solution {
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) : head_(head), count_(0), rnd_() {
    ListNode* node = head;
    while (node) {
      count_++;
      node = node->next;
    }
  }

  /** Returns a random node's value. */
  int getRandom() {
    unsigned int rand = rnd_() % count_;
    unsigned int count = 0;
    ListNode* node = head_;
    while (count < rand) {
      count++;
      node = node->next;
    }
    return node->val;
  }

 private:
  ListNode* head_;
  size_t count_;
  random_device rnd_;
};

int main() {
  vector<int> vec = {1, 2, 3, 4};
  ListNode* head = CreateListNode(vec);
  Solution sol(head);
  for (size_t i = 0; i < 5; ++i) {
    sol.getRandom();
  }
  DeleteListNode(head);

  exit(EXIT_SUCCESS);
}
