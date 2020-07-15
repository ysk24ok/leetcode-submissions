from typing import *


class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        ret = []
        for word in words:
            if word == '':
                continue
            ret.insert(0, word)
        return ' '.join(ret)


if __name__ == '__main__':
    sol = Solution()

    s, expected = "the sky is blue", "blue is sky the"
    assert sol.reverseWords(s) == expected

    s, expected = "  hello world!  ", "world! hello"
    assert sol.reverseWords(s) == expected

    s, expected = "a good   example", "example good a"
    assert sol.reverseWords(s) == expected
