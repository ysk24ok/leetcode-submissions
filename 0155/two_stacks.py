class MinStack:
    def __init__(self):
        self._stack = []
        self._mins = []

    def push(self, val: int) -> None:
        self._stack.append(val)
        if len(self._mins) == 0:
            self._mins.append(val)
            return
        if val <= self.getMin():
            self._mins.append(val)

    def pop(self) -> None:
        assert len(self._stack) > 0
        val = self._stack.pop()
        if val == self._mins[-1]:
            self._mins.pop()

    def top(self) -> int:
        assert len(self._stack) > 0
        return self._stack[-1]

    def getMin(self) -> int:
        assert len(self._stack) > 0
        return self._mins[-1]


if __name__ == '__main__':
    min_stack = MinStack()
    min_stack.push(-2)
    min_stack.push(0)
    min_stack.push(-3)
    assert min_stack.getMin() == -3
    min_stack.pop()
    assert min_stack.top() == 0
    assert min_stack.getMin() == -2

    min_stack = MinStack()
    min_stack.push(0)
    min_stack.push(1)
    min_stack.push(0)
    assert min_stack.getMin() == 0
    min_stack.pop()
    assert min_stack.getMin() == 0

    min_stack = MinStack()
    min_stack.push(2147483646)
    min_stack.push(2147483646)
    min_stack.push(2147483647)
    assert min_stack.top() == 2147483647
    min_stack.pop()
    assert min_stack.getMin() == 2147483646
    min_stack.pop()
    assert min_stack.getMin() == 2147483646
    min_stack.pop()
    min_stack.push(2147483647)
    assert min_stack.top() == 2147483647
    assert min_stack.getMin() == 2147483647
    min_stack.push(-2147483648)
    assert min_stack.top() == -2147483648
    assert min_stack.getMin() == -2147483648
    min_stack.pop()
    assert min_stack.getMin() == 2147483647
