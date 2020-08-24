from typing import List


class TrieNode:

    def __init__(self):
        self._nodes = [None for _ in range(26)]
        self._endsWith = [False for _ in range(26)]

    def add(self, word, idx):
        char_id = ord(word[idx]) - ord('a')
        if idx == len(word) - 1:
            self._endsWith[char_id] = True
        else:
            if self._nodes[char_id] is None:
                self._nodes[char_id] = TrieNode()
            self._nodes[char_id].add(word, idx+1)

    def query(self, char_id):
        return self._nodes[char_id]

    def endsWith(self, char_id):
        return self._endsWith[char_id]


class StreamChecker:

    """Let
    - the size of `words` be M
    - the maximum length of a word in `words` be N

    time complexity (of query()): O(`waiting_list`)
                                  = O(1 + 26 + 26**2 + ... + 26**(N-1))
                                  = O(26 ** N - 1)
        e.g. words which ends with 'a':
            - a
            - aa, ..., za
            - aaa, ..., zza
            - ...
    """

    def __init__(self, words: List[str]):
        self.node = TrieNode()
        for word in words:
            self.node.add(word, 0)
        self.waiting_list = [self.node]

    def query(self, letter: str) -> bool:
        char_id = ord(letter) - ord('a')
        exists = False
        new_waiting_list = []
        for node in self.waiting_list:
            if node.endsWith(char_id):
                exists = True
            next_node = node.query(char_id)
            if next_node is not None:
                new_waiting_list.append(next_node)
        new_waiting_list.append(self.node)
        self.waiting_list = new_waiting_list
        return exists


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
