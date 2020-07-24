class Solution:
    """stack[n] is a score of depth n.
              -> stack: [0]
    (         -> stack: [0,0]
    ((        -> stack: [0,0,0]
    (()       -> stack: [0,1]
    (()(      -> stack: [0,1,0]
    (()((     -> stack: [0,1,0,0]
    (()(()    -> stack: [0,1,1]
    (()(())   -> stack: [0,3]
    (()(()))  -> stack: [6]
    """
    def scoreOfParentheses(self, S: str) -> int:
        stack = [0]
        for c in S:
            if c == '(':
                stack.append(0)
            else:
                score = stack.pop()
                if score == 0:
                    stack[-1] += 1
                else:
                    stack[-1] += score * 2
        return stack[-1]


if __name__ == '__main__':
    sol = Solution()

    S = "()"
    expected = 1
    assert sol.scoreOfParentheses(S) == expected

    S = "(())"
    expected = 2
    assert sol.scoreOfParentheses(S) == expected

    S = "()()"
    expected = 2
    assert sol.scoreOfParentheses(S) == expected

    S = "(()(()))"
    expected = 6
    assert sol.scoreOfParentheses(S) == expected
