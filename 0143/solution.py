from leetcode.linked_list import ListNode, String2LinkedList, LinkedList2String


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head is None or head.next is None or head.next.next is None:
            return
        middle = head
        faster = head
        while faster.next is not None and faster.next.next is not None:
            middle = middle.next
            faster = faster.next.next

        # Reverse latter half
        # 1 -> 2 -> 3 -> 4      => 1 -> 2 -> 4 -> 3
        # 1 -> 2 -> 3 -> 4 -> 5 => 1 -> 2 -> 3 -> 5 -> 4
        prev = middle
        curr = prev.next
        next = curr.next
        curr.next = None
        while next is not None:
            next_of_next = next.next
            next.next = curr
            prev.next = next
            curr = next
            next = next_of_next

        # insert `latter` node between `prev` and `curr`
        #
        # 1 2, 4 3 => 1 4 2  , 3
        # p c  l          p c  l
        #
        # 1 2 3, 5 4 => 1 5 2 3, 4 => 1 5 2 4 3
        # p c    l          p c  l      c     p c,l
        prev = head
        curr = prev.next
        latter = middle.next
        middle.next = None
        while curr is not None:
            next_of_latter = latter.next
            prev.next = latter
            prev.next.next = curr
            prev = curr
            curr = prev.next
            latter = next_of_latter
        if latter is not None:
            prev.next = latter


if __name__ == '__main__':
    sol = Solution()

    head = String2LinkedList("1 2 3 4")
    sol.reorderList(head)
    expected = "1 4 2 3"
    assert LinkedList2String(head) == expected

    head = String2LinkedList("1 2 3 4 5")
    sol.reorderList(head)
    expected = "1 5 2 4 3"
    assert LinkedList2String(head) == expected

    head = String2LinkedList("1 2")
    sol.reorderList(head)
    expected = "1 2"
    assert LinkedList2String(head) == expected

    head = String2LinkedList("1 2 3")
    sol.reorderList(head)
    expected = "1 3 2"
    assert LinkedList2String(head) == expected
