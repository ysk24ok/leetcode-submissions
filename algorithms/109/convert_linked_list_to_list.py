# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def _getNodes(self, head):
        nodes = [TreeNode(head.val)]
        head = head.next
        while head is not None:
            nodes.append(TreeNode(head.val))
            head = head.next
        return nodes

    def _recursion(self, nodes):
        if len(nodes) == 1:
            return nodes[0]
        if len(nodes) == 2:
            node = nodes[1]
            node.left = nodes[0]
            return node
        middle_idx = int(len(nodes) / 2)
        node = nodes[middle_idx]
        node.left = self._recursion(nodes[:middle_idx])
        node.right = self._recursion(nodes[middle_idx+1:])
        return node

    def sortedListToBST(self, head: ListNode) -> TreeNode:
        """Convert linked list to list
        and use recursion to get a height-balanced binary search tree
        """
        if head is None:
            return None
        nodes = self._getNodes(head)
        return self._recursion(nodes)


def create_nodes(values):
    if len(values) == 0:
        return None
    next_node = ListNode(values[-1])
    for val in values[:-1][::-1]:
        node = ListNode(val)
        node.next = next_node
        next_node = node
    return next_node


if __name__ == '__main__':
    sol = Solution()
    #      0
    #     / \
    #   -3   9
    #   /   /
    # -10  5
    node = create_nodes([-10, -3, 0, 5, 9])
    got = sol.sortedListToBST(node)
    assert got.val == 0
    assert got.left.val == -3
    assert got.right.val == 9
    assert got.left.left.val == -10
    assert got.left.right is None
    assert got.right.left.val == 5
    assert got.right.right is None

    node = create_nodes([])
    got = sol.sortedListToBST(node)
    assert got is None

    node = create_nodes([1])
    got = sol.sortedListToBST(node)
    assert got.val is 1
    assert got.left is None
    assert got.right is None

    node = create_nodes([1, 3])
    got = sol.sortedListToBST(node)
    assert got.val is 3
    assert got.left.val is 1
    assert got.right is None
