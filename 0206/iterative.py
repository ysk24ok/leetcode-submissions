class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        next = None
        node = head
        while node is not None:
            curr = ListNode(node.val)
            curr.next = next
            next = curr
            node = node.next
        return next


if __name__ == '__main__':
    sol = Solution()

    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    got = sol.reverseList(head)
    assert got.val == 5
    assert got.next.val == 4
    assert got.next.next.val == 3
    assert got.next.next.next.val == 2
    assert got.next.next.next.next.val == 1
    assert got.next.next.next.next.next is None

    assert sol.reverseList(None) is None
