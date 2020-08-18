class ListNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = ListNode(0, 0)
        self.tail = ListNode(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.nodes = {}

    def get(self, key: int) -> int:
        if key not in self.nodes:
            return -1
        node = self.nodes[key]
        self._pick_up_node(node)
        self._add_node_to_head(node)
        return node.value

    def put(self, key: int, value: int) -> None:
        # no eviction is needed
        if key in self.nodes:
            node = self.nodes[key]
            node.value = value
            self._pick_up_node(node)
            self._add_node_to_head(node)
            return
        # eviction
        if key not in self.nodes and len(self.nodes) == self.capacity:
            self._remove_least_recent_node()
        node = ListNode(key, value)
        self.nodes[key] = node
        self._add_node_to_head(node)

    def _pick_up_node(self, node):
        prev_node = node.prev
        next_node = node.next
        prev_node.next = next_node
        next_node.prev = prev_node

    def _add_node_to_head(self, node):
        next_node = self.head.next
        node.next = next_node
        next_node.prev = node
        self.head.next = node
        node.prev = self.head

    def _remove_least_recent_node(self):
        node_to_delete = self.tail.prev
        prev_node = node_to_delete.prev
        if prev_node is None:
            return
        prev_node.next = self.tail
        self.tail.prev = prev_node
        del self.nodes[node_to_delete.key]


if __name__ == '__main__':
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    assert cache.get(1) == 1
    cache.put(3, 3)     # evicts key 2
    assert cache.get(2) == -1
    cache.put(4, 4)     # evicts key 4
    assert cache.get(1) == -1
    assert cache.get(3) == 3
    assert cache.get(4) == 4

    cache = LRUCache(2)
    cache.put(2, 1)
    cache.put(2, 2)
    assert cache.get(2) == 2
    cache.put(1, 1)
    cache.put(4, 1)
    assert cache.get(2) == -1
