class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        d1, d2 = {}, {}
        words = str.split()
        if len(pattern) != len(words):
            return False
        for c, word in zip(pattern, words):
            if c not in d1:
                d1[c] = word
            elif d1[c] != word:
                return False
            if word not in d2:
                d2[word] = c
            elif d2[word] != c:
                return False
        return True


if __name__ == '__main__':
    sol = Solution()

    pattern, str = "abba", "dog cat cat dog"
    assert sol.wordPattern(pattern, str)

    pattern, str = "abba", "dog cat cat fish"
    assert not sol.wordPattern(pattern, str)

    pattern, str = "aaaa", "dog cat cat dog"
    assert not sol.wordPattern(pattern, str)

    pattern, str = "abba", "dog dog dog dog"
    assert not sol.wordPattern(pattern, str)

    pattern, str = "aaa", "aa aa aa aa"
    assert not sol.wordPattern(pattern, str)
