from typing import *


class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        expected_counts = 2 ** k
        mask = expected_counts - 1
        unique = set([])
        hash_val = 0
        for i in range(len(s)):
            hash_val <<= 1
            hash_val &= mask
            hash_val += int(s[i])
            if i < k - 1:
                continue
            unique.add(hash_val)
            if len(unique) == expected_counts:
                return True
        return False


if __name__ == '__main__':
    sol = Solution()

    s, k, expected = ("00110110", 2, True)
    assert sol.hasAllCodes(s, k) is expected

    s, k, expected = ("0110", 1, True)
    assert sol.hasAllCodes(s, k) is expected

    s, k, expected = ("0110", 2, False)
    assert sol.hasAllCodes(s, k) is expected

    s, k, expected = ("0", 20, False)
    assert sol.hasAllCodes(s, k) is expected

    s, k, expected = ("101000100011111001110010", 3, True)
    assert sol.hasAllCodes(s, k) is expected

    s, k, expected = ("00110", 2, True)
    assert sol.hasAllCodes(s, k) is expected

    s, k, expected = ("000011010111011001001111111001000100100100010100101100001101101101110001100100101111100111001001111001001010111010010101101001001110011100110101001001001000000110101001010011101100110110100010000", 7, False)
    assert sol.hasAllCodes(s, k) is expected
