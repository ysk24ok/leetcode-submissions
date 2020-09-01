class LFUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.items = {}
        self.timesteps = 0

    def get(self, key: int) -> int:
        self.timesteps += 1
        if key not in self.items:
            return -1
        self.items[key]['freq'] += 1
        self.items[key]['timesteps'] = self.timesteps
        return self.items[key]['value']

    def put(self, key: int, value: int) -> None:
        self.timesteps += 1
        if self.capacity == 0:
            return
        if key in self.items:
            self.items[key]['value'] = value
            self.items[key]['freq'] += 1
            self.items[key]['timesteps'] = self.timesteps
            return
        if len(self.items) == self.capacity:
            least_frequency = 2 ** 31 - 1
            least_frequent_key = None
            timesteps = 0
            for k, item in self.items.items():
                if item['freq'] < least_frequency:
                    least_frequency = item['freq']
                    least_frequent_key = k
                    timesteps = item['timesteps']
                elif item['freq'] == least_frequency \
                        and item['timesteps'] < timesteps:
                    least_frequent_key = k
                    timesteps = item['timesteps']
            del self.items[least_frequent_key]
        self.items[key] = {
            'value': value,
            'freq': 1,
            'timesteps': self.timesteps
        }


if __name__ == '__main__':
    capacity = 2
    cache = LFUCache(capacity)
    cache.put(1, 1)
    cache.put(2, 2)
    assert cache.get(1) == 1
    cache.put(3, 3)     # evicts key 2
    assert cache.get(2) == -1
    assert cache.get(3) == 3
    cache.put(4, 4)     # evicts key 1
    assert cache.get(1) == -1
    assert cache.get(3) == 3
    assert cache.get(4) == 4

    capacity = 2
    cache = LFUCache(capacity)
    cache.put(3, 1)
    cache.put(2, 1)
    cache.put(2, 2)
    cache.put(4, 4)     # evicts key 3
    assert cache.get(2) == 2

    capacity = 0
    cache = LFUCache(capacity)
    cache.put(0, 0)
    assert cache.get(0) == -1

    capacity = 2
    cache = LFUCache(capacity)
    cache.put(2, 1)
    cache.put(3, 2)
    assert cache.get(3) == 2
    assert cache.get(2) == 1
    cache.put(4, 3)     # evicts key 3
    assert cache.get(2) == 1
    assert cache.get(3) == -1
    assert cache.get(4) == 3
