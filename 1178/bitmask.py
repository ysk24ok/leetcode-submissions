from typing import List
from collections import defaultdict


class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        def bitmask(word: str):
            n = 0
            for c in word:
                n |= 1 << (ord(c) - ord("a"))
            return n

        word_counter = defaultdict(int)
        for word in words:
            word_counter[bitmask(word)] += 1
        ret = []
        for puzzle in puzzles:
            first_mask = bitmask(puzzle[0])
            count = word_counter[first_mask]
            mask = bitmask(puzzle[1:])
            submask = mask
            while submask > 0:
                count += word_counter[submask | first_mask]
                submask = (submask - 1) & mask
            ret.append(count)
        return ret


if __name__ == "__main__":
    sol = Solution()

    words = ["aaaa", "asas", "able", "ability", "actt", "actor", "access"]
    puzzles = ["aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"]
    expected = [1, 1, 3, 2, 4, 0]
    assert sol.findNumOfValidWords(words, puzzles) == expected

    words = ["apple", "pleas", "please"]
    puzzles = ["aelwxyz", "aelpxyz", "aelpsxy", "saelpxy", "xaelpsy"]
    expected = [0, 1, 3, 2, 0]
    assert sol.findNumOfValidWords(words, puzzles) == expected
