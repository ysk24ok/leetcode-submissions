class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        while left < len(s) - 1 and not self.isAlphanumeric(s[left]):
            left += 1
        while right > 0 and not self.isAlphanumeric(s[right]):
            right -= 1
        while left <= right:
            if self.isSameNumeric(s[left], s[right]):
                left += 1
                right -= 1
            elif self.isSameAlphabet(s[left], s[right]):
                left += 1
                right -= 1
            elif s[left] == s[right]:
                left += 1
                right -= 1
            else:
                return False
            while left < len(s) - 1 and not self.isAlphanumeric(s[left]):
                left += 1
            while right > 0 and not self.isAlphanumeric(s[right]):
                right -= 1
        return True

    def isAlphanumeric(self, c):
        return self.isNumeric(c) or self.isAlphabet(c)

    def isSameNumeric(self, c1, c2):
        if not self.isNumeric(c1) or not self.isNumeric(c2):
            return False
        return c1 == c2

    def isNumeric(self, c):
        diff = ord(c) - ord('0')
        return True if 0 <= diff and diff <= 9 else False

    def isSameAlphabet(self, c1, c2):
        if not self.isAlphabet(c1) or not self.isAlphabet(c2):
            return False
        diff = abs(ord(c1) - ord(c2))
        expected_diff = abs(ord('A') - ord('a'))
        return True if diff == 0 or diff == expected_diff else False

    def isAlphabet(self, c):
        return True if self.isUppercase(c) or self.isLowercase(c) else False

    def isUppercase(self, c):
        diff = ord(c) - ord('A')
        return True if 0 <= diff and diff <= 25 else False

    def isLowercase(self, c):
        diff = ord(c) - ord('a')
        return True if 0 <= diff and diff <= 25 else False


if __name__ == '__main__':
    sol = Solution()

    assert not sol.isAlphanumeric(' ')
    assert not sol.isAlphanumeric(':')
    assert not sol.isAlphanumeric(',')

    s = "A man, a plan, a canal: Panama"
    assert sol.isPalindrome(s)

    s = " A man, a plan, a canal: Panama  "
    assert sol.isPalindrome(s)

    s = "race a car"
    assert not sol.isPalindrome(s)

    s = " "
    assert sol.isPalindrome(s)
