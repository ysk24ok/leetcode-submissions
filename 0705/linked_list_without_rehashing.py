N = 1024


class ListNode:
    def __init__(self, x):
        self.key = x
        self.next = None


class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._bucket = [None for _ in range(N)]

    def add(self, key: int) -> None:
        hashed = key % N
        new_node = ListNode(key)
        if self._bucket[hashed] is None:
            self._bucket[hashed] = new_node
            return
        dummy = ListNode(None)
        prev = dummy
        node = self._bucket[hashed]
        dummy.next = node
        while node is not None:
            if node.key == key:
                return
            prev = node
            node = node.next
        prev.next = new_node

    def remove(self, key: int) -> None:
        hashed = key % N
        dummy = ListNode(None)
        prev = dummy
        node = self._bucket[hashed]
        dummy.next = node
        while node is not None:
            if node.key == key:
                prev.next = node.next
                break
            prev = node
            node = node.next
        self._bucket[hashed] = dummy.next

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        hashed = key % N
        node = self._bucket[hashed]
        while node is not None:
            if node.key == key:
                return True
        return False


if __name__ == '__main__':
    hashset = MyHashSet()
    hashset.add(1)
    hashset.add(2)
    assert hashset.contains(1)
    assert hashset.contains(2)
    assert not hashset.contains(3)
    hashset.add(2)
    assert hashset.contains(2)
    hashset.remove(2)
    assert not hashset.contains(2)
