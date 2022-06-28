from typing import *


class Solution:
    def minDeletions(self, s: str) -> int:
        freq_per_char = {}
        for c in s:
            if c not in freq_per_char:
                freq_per_char[c] = 0
            freq_per_char[c] += 1
        seen_freq = set([])
        delete_count = 0
        for freq in freq_per_char.values():
            while freq in seen_freq:
                delete_count += 1
                freq -= 1
            if freq > 0:
                seen_freq.add(freq)
        return delete_count


if __name__ == '__main__':
    sol = Solution()

    s, expected = "aab", 0
    assert sol.minDeletions(s) == expected

    s, expected = "aaabbbcc", 2
    assert sol.minDeletions(s) == expected

    s, expected = "ceabaacb", 2
    assert sol.minDeletions(s) == expected

    s, expected = "bbcebab", 2
    assert sol.minDeletions(s) == expected
