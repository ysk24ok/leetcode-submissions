from typing import List


class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        unique_chars_per_puzzles = {}
        for puzzle in puzzles:
            unique_chars_per_puzzles[puzzle] = set(puzzle)
        unique_chars_per_words = {}
        for word in words:
            unique_chars_per_words[word] = set(word)
        ret = []
        for puzzle, puzzle_chars in unique_chars_per_puzzles.items():
            count = 0
            for word, word_chars in unique_chars_per_words.items():
                if puzzle[0] not in word_chars:
                    continue
                is_valid = True
                for c in word_chars:
                    if c not in puzzle_chars:
                        is_valid = False
                if is_valid:
                    count += 1
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
