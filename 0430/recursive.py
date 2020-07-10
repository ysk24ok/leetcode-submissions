from typing import *

# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def flatten(self, head: Node) -> Node:
        dummy = Node(-1, None, None, None)
        self.dfs(head, dummy)
        if dummy.next is not None:
            dummy.next.prev = None
        return dummy.next

    def dfs(self, node, prev):
        while node is not None:
            new_node = Node(node.val, prev, None, None)
            prev.next = new_node
            if node.child is not None:
                self.dfs(node.child, prev.next)
            while prev.next is not None:
                prev = prev.next
            node = node.next


if __name__ == '__main__':
    sol = Solution()

    head = Node(1, None, None, None)
    head.next = Node(2, head, None, None)
    head.child = Node(3, None, None, None)
    got = sol.flatten(head)
    assert got.val == 1
    assert got.next.val == 3
    assert got.next.prev.val == 1
    assert got.next.next.val == 2
    assert got.next.next.prev.val == 3
    assert got.next.next.next is None

    assert sol.flatten(None) is None
