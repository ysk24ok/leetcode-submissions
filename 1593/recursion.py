class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        unique_words = set([])
        return self.recursion(s, 0, unique_words)

    def recursion(self, s, idx, unique_words):
        if idx == len(s):
            return len(unique_words)
        maxval = -1
        for jdx in range(idx+1, len(s)+1):
            substr = s[idx:jdx]
            if substr in unique_words:
                count = self.recursion(s, jdx, unique_words)
            else:
                unique_words.add(substr)
                count = self.recursion(s, jdx, unique_words)
                unique_words.remove(substr)
            maxval = max(maxval, count)
        return maxval


if __name__ == '__main__':
    sol = Solution()

    s = "ababccc"
    expected = 5
    assert sol.maxUniqueSplit(s) == expected

    s = "aba"
    expected = 2
    assert sol.maxUniqueSplit(s) == expected

    s = "aa"
    expected = 1
    assert sol.maxUniqueSplit(s) == expected

    s = "addbsd"
    expected = 5
    assert sol.maxUniqueSplit(s) == expected
