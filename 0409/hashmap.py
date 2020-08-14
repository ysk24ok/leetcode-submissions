from collections import defaultdict


class Solution:
    def longestPalindrome(self, s: str) -> int:
        counts = defaultdict(int)
        for c in s:
            counts[c] += 1
        ret = 0
        has_one = False
        for count in counts.values():
            if count % 2 == 1:
                ret += count - 1
                if not has_one:
                    ret += 1
                    has_one = True
            else:
                ret += count
        return ret


if __name__ == '__main__':
    sol = Solution()

    s, expected = "abccccdd", 7
    assert sol.longestPalindrome(s) == expected

    s, expected = "ab", 1
    assert sol.longestPalindrome(s) == expected

    s, expected = "abab", 4
    assert sol.longestPalindrome(s) == expected

    s, expected = "aaabbb", 5
    assert sol.longestPalindrome(s) == expected
