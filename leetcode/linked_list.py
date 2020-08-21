# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def String2LinkedList(s: str) -> ListNode:
    dummy = ListNode(0)
    prev = dummy
    for c in s.split():
        curr = ListNode(int(c))
        prev.next = curr
        prev = curr
    return dummy.next


def LinkedList2String(node: ListNode) -> str:
    s = []
    while node is not None:
        s.append(str(node.val))
        node = node.next
    return ' '.join(s)
