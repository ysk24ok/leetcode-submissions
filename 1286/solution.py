class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.characters = characters
        self.indices = [i for i in range(combinationLength)]
        self._hasNext = True

    def next(self) -> str:
        ret = ''.join([self.characters[i] for i in self.indices])
        self._update_indices()
        return ret

    def _update_indices(self):
        maxval = len(self.characters) - 1
        for i in reversed(range(len(self.indices))):
            if self.indices[i] < maxval:
                self.indices[i] += 1
                for j in range(i+1, len(self.indices)):
                    self.indices[j] = self.indices[j-1] + 1
                return
            maxval -= 1
        # When no update occurs, that means there is no next
        self._hasNext = False

    def hasNext(self) -> bool:
        return self._hasNext


if __name__ == '__main__':
    iterator = CombinationIterator("abc", 2)
    assert iterator.next() == "ab"
    assert iterator.hasNext()
    assert iterator.next() == "ac"
    assert iterator.hasNext()
    assert iterator.next() == "bc"
    assert not iterator.hasNext()

    iterator = CombinationIterator("abcd", 2)
    assert iterator.next() == "ab"
    assert iterator.hasNext()
    assert iterator.next() == "ac"
    assert iterator.hasNext()
    assert iterator.next() == "ad"
    assert iterator.hasNext()
    assert iterator.next() == "bc"
    assert iterator.hasNext()
    assert iterator.next() == "bd"
    assert iterator.hasNext()
    assert iterator.next() == "cd"
    assert not iterator.hasNext()
