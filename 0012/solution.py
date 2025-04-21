from typing import *


class Solution:
    def intToRoman(self, num: int) -> str:
        mapping = [("", "", "M", 1000), ("M", "D", "C", 100), ("C", "L", "X", 10), ("X", "V", "I", 1)]
        chars = []
        for char10, char5, char1, value in mapping:
            quotient = int(num / value)
            num -= quotient * value
            if quotient == 9:
                chars.append(char1)
                chars.append(char10)
            elif quotient >= 5:
                chars.append(char5)
                for _ in range(quotient - 5):
                    chars.append(char1)
            elif quotient == 4:
                chars.append(char1)
                chars.append(char5)
            else:
                for _ in range(quotient):
                    chars.append(char1)
        return "".join(chars)


if __name__ == '__main__':
    sol = Solution()
    assert sol.intToRoman(3749) == "MMMDCCXLIX"
    assert sol.intToRoman(58) == "LVIII"
    assert sol.intToRoman(1994) == "MCMXCIV"
