from queue import Queue
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        ret = []
        if root is None:
            return ret
        stack = []
        stack.append((root, 0))
        while len(stack) > 0:
            q = Queue()
            while len(stack) > 0:
                q.put(stack.pop())
            while not q.empty():
                node, level = q.get()
                if len(ret) == level:
                    ret.append([])
                ret[level].append(node.val)
                if level % 2 == 0:
                    if node.left is not None:
                        stack.append((node.left, level+1))
                    if node.right is not None:
                        stack.append((node.right, level+1))
                else:
                    if node.right is not None:
                        stack.append((node.right, level+1))
                    if node.left is not None:
                        stack.append((node.left, level+1))
        return ret


if __name__ == '__main__':
    sol = Solution()

    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    expected = [[3], [20, 9], [15, 7]]
    assert sol.zigzagLevelOrder(root) == expected

    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.right.right = TreeNode(5)
    expected = [[1], [3, 2], [4, 5]]
    assert sol.zigzagLevelOrder(root) == expected
