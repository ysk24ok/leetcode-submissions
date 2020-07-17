from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        length = 0
        curr = head
        while curr is not None:
            length += 1
            curr = curr.next
        dummy = ListNode(0)
        dummy.next = head
        step = 1
        while True:
            if step > length:
                break
            curr = dummy.next
            tail = dummy
            while curr is not None:
                left = curr
                right = self.split(left, step)
                curr = self.split(right, step)
                tail = self.merge(tail, left, right)
            step <<= 1
        return dummy.next

    def split(self, curr, step):
        i = 0
        while i < step:
            if curr is None:
                return None
            if i == step - 1:
                next_head = curr.next
                curr.next = None
            curr = curr.next
            i += 1
        return next_head

    def merge(self, tail, left, right):
        while left is not None and right is not None:
            if left.val < right.val:
                tail.next = left
                left = left.next
            else:
                tail.next = right
                right = right.next
            tail = tail.next
        node = left if left is not None else right
        while node is not None:
            tail.next = node
            node = node.next
            tail = tail.next
        tail.next = None
        return tail


if __name__ == '__main__':
    sol = Solution()

    head = ListNode(4)
    head.next = ListNode(2)
    head.next.next = ListNode(1)
    head.next.next.next = ListNode(3)
    got = sol.sortList(head)
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
    got = sol.sortList(head)
    assert got.val == -1
    assert got.next.val == 0
    assert got.next.next.val == 3
    assert got.next.next.next.val == 4
    assert got.next.next.next.next.val == 5
    assert got.next.next.next.next.next is None
