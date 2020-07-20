from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        prev_node, curr_node = dummy, head
        while curr_node is not None:
            if curr_node.val == val:
                prev_node.next = curr_node.next
                curr_node = prev_node.next
            else:
                prev_node = curr_node
                curr_node = curr_node.next
        return dummy.next


if __name__ == '__main__':
    sol = Solution()

    val = 6
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(6)
    head.next.next.next = ListNode(3)
    head.next.next.next.next = ListNode(4)
    head.next.next.next.next.next = ListNode(5)
    head.next.next.next.next.next.next = ListNode(6)
    got = sol.removeElements(head, val)
    assert got.val == 1
    assert got.next.val == 2
    assert got.next.next.val == 3
    assert got.next.next.next.val == 4
    assert got.next.next.next.next.val == 5
    assert got.next.next.next.next.next is None

    val = 0
    assert sol.removeElements(None, val) is None
