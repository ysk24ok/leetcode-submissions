from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def String2Tree(s: str) -> TreeNode:
    vals = s.split()
    if len(vals) == 0:
        return None
    root = TreeNode(int(vals[0]))
    q = deque()
    q.append(root)
    idx = 1
    while len(q) > 0:
        node = q.popleft()
        left_idx = idx
        if left_idx < len(vals) and vals[left_idx] != '#':
            node.left = TreeNode(int(vals[left_idx]))
            q.append(node.left)
        right_idx = idx + 1
        if right_idx < len(vals) and vals[right_idx] != '#':
            node.right = TreeNode(int(vals[right_idx]))
            q.append(node.right)
        idx += 2
    return root
