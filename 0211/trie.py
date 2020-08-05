class Node:
    def __init__(self):
        self.nodes = [None for _ in range(26)]
        self.endsWith = [False for _ in range(26)]


class Trie:
    def __init__(self):
        self.root = Node()

    def addWord(self, word):
        self._addWord(word, 0, self.root)

    def _addWord(self, word, idx, node):
        code = ord(word[idx]) - ord('a')
        if idx == len(word) - 1:
            node.endsWith[code] = True
            return
        if node.nodes[code] is None:
            node.nodes[code] = Node()
        self._addWord(word, idx+1, node.nodes[code])

    def search(self, word):
        return self._search(word, 0, self.root)

    def _search(self, word, idx, node):
        if word[idx] == '.':
            if idx == len(word) - 1:
                return any(node.endsWith)
            for next_node in node.nodes:
                if next_node is not None:
                    ret = self._search(word, idx+1, next_node)
                    if ret is True:
                        return True
            return False
        code = ord(word[idx]) - ord('a')
        if idx == len(word) - 1:
            return node.endsWith[code] is True
        if node.nodes[code] is None:
            return False
        return self._search(word, idx+1, node.nodes[code])


class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = Trie()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        if len(word) == 0:
            return
        self.trie.addWord(word)

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure.
        A word could contain the dot character '.' to represent any one letter.
        """
        if len(word) == 0:
            return
        return self.trie.search(word)


if __name__ == '__main__':
    d = WordDictionary()
    d.addWord("bad")
    d.addWord("dad")
    d.addWord("mad")
    assert not d.search("pad")
    assert d.search("bad")
    assert d.search(".ad")
    assert d.search("b..")
