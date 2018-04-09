# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l = []
        n1 = l1
        n2 = l2
        moving_up = 0
        while n1 is not None or n2 is not None:
            v1 = 0
            if n1 is not None:
                v1 = n1.val
                n1 = n1.next
            v2 = 0
            if n2 is not None:
                v2 = n2.val
                n2 = n2.next
            val = v1 + v2 + moving_up
            moving_up = int(val / 10)
            l.append(val % 10)
        if moving_up != 0:
            l.append(moving_up)
        return self.getLinkedListNodes(l)

    def getLinkedListNodes(self, l):
        """
        :type l: list[int]
        """
        leading_node = ListNode(l[-1])
        for n in reversed(l[:-1]):
            node = ListNode(n)
            node.next = leading_node
            leading_node = node
        return leading_node


if __name__ == '__main__':
    sol = Solution()
    l1 = sol.getLinkedListNodes([2, 4, 3])
    l2 = sol.getLinkedListNodes([5, 6, 4])
    ans = sol.addTwoNumbers(l1, l2)
    assert ans.val == 7 and ans.next.val == 0 and ans.next.next.val == 8
    l1 = sol.getLinkedListNodes([2, 5, 8])
    l2 = sol.getLinkedListNodes([0, 8, 3])
    ans = sol.addTwoNumbers(l1, l2)
    assert ans.val == 2 and ans.next.val == 3 and ans.next.next.val == 2 \
        and ans.next.next.next.val == 1
    l1 = sol.getLinkedListNodes([1, 8])
    l2 = sol.getLinkedListNodes([0])
    ans = sol.addTwoNumbers(l1, l2)
    assert ans.val == 1 and ans.next.val == 8
