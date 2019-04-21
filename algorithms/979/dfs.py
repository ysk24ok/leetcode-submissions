# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:

    def dfs(self, node: TreeNode) -> (int, int):
        if node is None:
            return 0, 0
        # when leaf node
        if node.left is None and node.right is None:
            # the parent node push 1 coin to this node
            if node.val == 0:
                return -1, 1
            # this node push (node.val - 1) coins to the parent node
            else:
                return node.val - 1, node.val - 1
        # when node.val == 0, node.left == 0 and node.right == 2, this node:
        #   pushes 1 coin to the left child node (left_move),
        #   pushes -1 coin to the right child node (right_move).
        #   pulls 1 coin from the parent node (move)
        left_move, left_count = self.dfs(node.left)
        right_move, right_count = self.dfs(node.right)
        move = node.val + left_move + right_move - 1
        return move, left_count + right_count + abs(move)

    def distributeCoins(self, root: TreeNode) -> int:
        return self.dfs(root)[1]


def create_binary_tree(values: list):
    power = 0
    total = 1
    nodes = []
    for idx, v in enumerate(values):
        # next row
        if idx >= total:
            power += 1
            total += 2 ** power
        if v is None:
            continue
        node = TreeNode(v)
        if idx == 0:
            pass
        elif idx % 2 == 1:
            parent = nodes[int(idx/2)]
            parent.left = node
        else:
            parent = nodes[int(idx/2)-1]
            parent.right = node
        nodes.append(node)
    return nodes[0]


if __name__ == '__main__':
    got = create_binary_tree([0, 1, 2, 3, 4, 5, 6, 7, 8])
    assert got.val == 0
    assert got.left.val == 1
    assert got.right.val == 2
    assert got.left.left.val == 3
    assert got.left.right.val == 4
    assert got.right.left.val == 5
    assert got.right.right.val == 6
    assert got.left.left.left.val == 7
    assert got.left.left.right.val == 8

    got = create_binary_tree([1, 0, 0, None, 3])
    assert got.val == 1
    assert got.left.val == 0
    assert got.right.val == 0
    assert got.right.left is None
    assert got.right.right is None
    assert got.left.left is None
    assert got.left.right.val == 3
    assert got.left.right.left is None
    assert got.left.right.right is None

    sol = Solution()
    node = create_binary_tree([3, 0, 0])
    got = sol.distributeCoins(node)
    assert got == 2

    node = create_binary_tree([0, 3, 0])
    got = sol.distributeCoins(node)
    assert got == 3

    node = create_binary_tree([1, 0, 2])
    got = sol.distributeCoins(node)
    assert got == 2

    node = create_binary_tree([1, 0, 0, None, 3])
    got = sol.distributeCoins(node)
    assert got == 4
