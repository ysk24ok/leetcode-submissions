# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head_node = ListNode(None)
        last_node = head_node
        while any(lists) is True:
            min_idx = argmin(lists)
            node = ListNode(lists[min_idx].val)
            last_node.next = node
            last_node = node
            lists[min_idx] = lists[min_idx].next
        return head_node.next


def argmin(lists):
    """
    :type lists: List[ListNode or None]
    """
    min_idx = None
    min_val = None
    for idx, node in enumerate(lists):
        if node is None:
            continue
        val = node.val
        if min_val is None or val < min_val:
            min_idx = idx
            min_val = val
    return min_idx


if __name__ == '__main__':
    # TODO: TLE
    sol = Solution()

    node1 = ListNode(6)
    node1.next = ListNode(8)
    node2 = ListNode(1)
    node2.next = ListNode(3)
    node3 = ListNode(3)
    node3.next = ListNode(10)
    got = sol.mergeKLists([node1, node2, node3])
    assert got.val == 1
    assert got.next.val == 3
    assert got.next.next.val == 3
    assert got.next.next.next.val == 6
    assert got.next.next.next.next.val == 8
    assert got.next.next.next.next.next.val == 10
    assert got.next.next.next.next.next.next is None

    got = sol.mergeKLists([])
    assert got is None

    got = sol.mergeKLists([None])
    assert got is None

    got = sol.mergeKLists([None, ListNode(1)])
    assert got.val == 1
    assert got.next is None
