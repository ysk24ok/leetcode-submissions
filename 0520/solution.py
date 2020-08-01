class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        num_small_letters = 0
        num_capital_letters = 0
        for c in word:
            if self.isCapitalLetter(c):
                num_capital_letters += 1
            else:
                num_small_letters += 1
        if self.isCapitalLetter(word[0]):
            if num_small_letters == 0:
                return True
            elif num_capital_letters == 1:
                return True
        else:
            if num_capital_letters == 0:
                return True
        return False

    def isCapitalLetter(self, c):
        diff = ord(c) - ord('A')
        if 0 <= diff and diff < 26:
            return True
        return False


if __name__ == '__main__':
    sol = Solution()

    word = "USA"
    assert sol.detectCapitalUse(word)

    word = "FlaG"
    assert not sol.detectCapitalUse(word)
