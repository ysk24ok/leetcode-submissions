class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        # search in order
        left_counter = 0
        right_counter = 0
        length = 0
        for c in s:
            if c == '(':
                left_counter += 1
            else:
                right_counter += 1
            # right parenthesis counter must be smaller than left one
            if right_counter > left_counter:
                right_counter = left_counter = 0
            elif right_counter == left_counter:
                length = max(length, right_counter + left_counter)
        # search in reverse order
        left_counter = 0
        right_counter = 0
        for c in s[::-1]:
            if c == '(':
                left_counter += 1
            else:
                right_counter += 1
            # left parenthesis counter must be smaller than right one
            if left_counter > right_counter:
                left_counter = right_counter = 0
            elif left_counter == right_counter:
                length = max(length, right_counter + left_counter)
        return length


if __name__ == '__main__':
    sol = Solution()
    # 1
    got = sol.longestValidParentheses('()')
    expected = 2
    assert got == expected, "got: {}, expected: {}".format(got, expected)
    # 2
    got = sol.longestValidParentheses(')(')
    expected = 0
    assert got == expected, "got: {}, expected: {}".format(got, expected)
    # 3
    got = sol.longestValidParentheses('(()')
    expected = 2
    assert got == expected, "got: {}, expected: {}".format(got, expected)
    # 4
    got = sol.longestValidParentheses('(())')
    expected = 4
    assert got == expected, "got: {}, expected: {}".format(got, expected)
    # 5
    got = sol.longestValidParentheses(')()())')
    expected = 4
    assert got == expected, "got: {}, expected: {}".format(got, expected)
    # 6
    got = sol.longestValidParentheses(')()(())())')
    expected = 8
    assert got == expected, "got: {}, expected: {}".format(got, expected)
    # 7
    got = sol.longestValidParentheses('(()((()')
    expected = 2
    assert got == expected, "got: {}, expected: {}".format(got, expected)
