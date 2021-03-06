from typing import List


class TrieNode:

    def __init__(self):
        self._nodes = [None for _ in range(26)]
        self._isEnd = False

    def add(self, word, idx):
        if idx == len(word):
            self._isEnd = True
        else:
            char_id = ord(word[idx]) - ord('a')
            if self._nodes[char_id] is None:
                self._nodes[char_id] = TrieNode()
            self._nodes[char_id].add(word, idx+1)

    def query(self, word, idx):
        if self._isEnd is True:
            return True
        if idx == len(word):
            return False
        char_id = ord(word[idx]) - ord('a')
        if self._nodes[char_id] is None:
            return False
        return self._nodes[char_id].query(word, idx+1)


class StreamChecker:

    """Let
    - the size of `words` be M
    - the maximum length of a word in `words` be N

    time complexity (of query()): O(N)
    """

    def __init__(self, words: List[str]):
        self.node = TrieNode()
        self.letters = ""
        self.max_word_length = 0
        for word in words:
            self.max_word_length = max(self.max_word_length, len(word))
            self.node.add(word[::-1], 0)

    def query(self, letter: str) -> bool:
        self.letters = (letter + self.letters)[:self.max_word_length]
        return self.node.query(self.letters, 0)


if __name__ == '__main__':
    words = ["cd", "f", "kl"]
    streamChecker = StreamChecker(words)
    assert not streamChecker.query('a')
    assert not streamChecker.query('b')
    assert not streamChecker.query('c')
    assert streamChecker.query('d')
    assert not streamChecker.query('e')
    assert streamChecker.query('f')
    assert not streamChecker.query('g')
    assert not streamChecker.query('h')
    assert not streamChecker.query('i')
    assert not streamChecker.query('j')
    assert not streamChecker.query('k')
    assert streamChecker.query('l')

    words = ["cd", "cdd"]
    streamChecker = StreamChecker(words)
    assert not streamChecker.query('c')
    assert streamChecker.query('d')
    assert streamChecker.query('d')

    words = ["ab", "ba", "aaab", "abab", "baa"]
    streamChecker = StreamChecker(words)
    assert not streamChecker.query('a')
    assert not streamChecker.query('a')
    assert not streamChecker.query('a')
    assert not streamChecker.query('a')
    assert not streamChecker.query('a')
    assert streamChecker.query('b')
    assert streamChecker.query('a')
    assert streamChecker.query('b')
