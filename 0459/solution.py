class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        substr = s[0]
        for i in range(1, n):
            if s[i] != substr[0]:
                substr += s[i]
                continue
            if n % len(substr) != 0:
                substr += s[i]
                continue
            repeated = True
            for j in range(i, n, len(substr)):
                if s[j:j+len(substr)] != substr:
                    repeated = False
                    break
            if repeated:
                return True
            substr += s[i]
        return False


if __name__ == '__main__':
    sol = Solution()

    s = "abab"
    assert sol.repeatedSubstringPattern(s)

    s = "aba"
    assert not sol.repeatedSubstringPattern(s)

    s = "abcabcabc"
    assert sol.repeatedSubstringPattern(s)

    s = "abcabdabcabd"
    assert sol.repeatedSubstringPattern(s)

    s = "abcabcabcabd"
    assert not sol.repeatedSubstringPattern(s)
