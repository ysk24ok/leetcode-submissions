#include <gtest/gtest.h>

#include <vector>

#include "leetcode/linked_list.hpp"

using namespace std;
using namespace LeetCode;

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* nodeA = headA;
    ListNode* nodeB = headB;
    // The first pointer moves m + scanB and the second one moves n + scanA
    // until both reaches the intersection.
    // If there is not intersection, both pointers move m + n and both reach null.
    while (nodeA != nodeB) {
      nodeA = nodeA ? nodeA->next : headB;
      nodeB = nodeB ? nodeB->next : headA;
    }
    return nodeA;
  }
};


int main() {
  Solution sol;
  vector<int> vecA, vecB;
  int skipA, skipB;
  ListNode* heads[] = {NULL, NULL};
  ListNode* got;

  vecA = {4,1,8,4,5}, vecB = {5,6,1,8,4,5}, skipA = 2, skipB = 3;
  CreateTwoListNodesWithIntersection(vecA, vecB, skipA, skipB, heads);
  got = sol.getIntersectionNode(heads[0], heads[1]);
  EXPECT_EQ(got, heads[0]->next->next);
  EXPECT_EQ(got, heads[1]->next->next->next);
  DeleteTwoListNodesWithIntersection(heads, skipA, skipB);

  vecA = {1,9,1,2,4}, vecB = {3,2,4}, skipA = 3, skipB = 1;
  CreateTwoListNodesWithIntersection(vecA, vecB, skipA, skipB, heads);
  got = sol.getIntersectionNode(heads[0], heads[1]);
  EXPECT_EQ(got, heads[0]->next->next->next);
  EXPECT_EQ(got, heads[1]->next);
  DeleteTwoListNodesWithIntersection(heads, skipA, skipB);

  vecA = {2,6,4}, vecB = {1,5}, skipA = 3, skipB = 2;
  CreateTwoListNodesWithIntersection(vecA, vecB, skipA, skipB, heads);
  got = sol.getIntersectionNode(heads[0], heads[1]);
  EXPECT_FALSE(got);
  DeleteTwoListNodesWithIntersection(heads, skipA, skipB);

  exit(EXIT_SUCCESS);
}
