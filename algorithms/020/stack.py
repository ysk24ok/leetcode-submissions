class Element:

    def __init__(self, val):
        self.val = val
        self.prev = None


class Stack:

    def __init__(self):
        self.head = None
        self.length = 0

    def push(self, val):
        element = Element(val)
        element.prev = self.head
        self.head = element
        self.length += 1

    def pop(self):
        if self.head is None:
            return None
        element = self.head
        self.head = self.head.prev
        self.length -= 1
        return element


class Solution:

    def isValid(self, s: str) -> bool:
        stack = Stack()
        for c in s:
            if c == '(' or c == '{' or c == '[':
                stack.push(c)
            else:
                element = stack.pop()
                if element is None:
                    return False
                if c == ')' and element.val != '(':
                    return False
                elif c == '}' and element.val != '{':
                    return False
                elif c == ']' and element.val != '[':
                    return False
        return True if stack.length == 0 else False


if __name__ == '__main__':
    sol = Solution()
    assert sol.isValid('()') is True
    assert sol.isValid('()[]{}') is True
    assert sol.isValid('(]') is False
    assert sol.isValid('([)]') is False
    assert sol.isValid('{[]}') is True
    assert sol.isValid('}{') is False
    assert sol.isValid('()(') is False
