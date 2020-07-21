from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        node = head
        while node is not None:
            node_to_insert = node
            node = node.next
            node_to_insert.next = None
            self.searchAndInsert(dummy, dummy.next, node_to_insert)
        return dummy.next

    def searchAndInsert(self, prev_node, curr_node, node_to_insert):
        assert node_to_insert.next is None
        while curr_node is not None:
            if curr_node.val > node_to_insert.val:
                prev_node.next = node_to_insert
                node_to_insert.next = curr_node
                return
            prev_node = curr_node
            curr_node = curr_node.next
        prev_node.next = node_to_insert


if __name__ == '__main__':
    sol = Solution()

    head = ListNode(4)
    head.next = ListNode(2)
    head.next.next = ListNode(1)
    head.next.next.next = ListNode(3)
    got = sol.insertionSortList(head)
    assert got.val == 1
    assert got.next.val == 2
    assert got.next.next.val == 3
    assert got.next.next.next.val == 4
    assert got.next.next.next.next is None

    head = ListNode(-1)
    head.next = ListNode(5)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(0)
    got = sol.insertionSortList(head)
    assert got.val == -1
    assert got.next.val == 0
    assert got.next.next.val == 3
    assert got.next.next.next.val == 4
    assert got.next.next.next.next.val == 5
    assert got.next.next.next.next.next is None

    assert sol.insertionSortList(None) is None
