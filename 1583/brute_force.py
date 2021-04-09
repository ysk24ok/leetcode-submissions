from typing import List


class Solution:
    def unhappyFriends(self, n: int, preferences: List[List[int]],
                       pairs: List[List[int]]) -> int:
        paired = [0 for _ in range(n)]
        for pair in pairs:
            paired[pair[0]] = pair[1]
            paired[pair[1]] = pair[0]
        ret = 0
        for person in range(n):
            is_unhappy = False
            for prefer in preferences[person]:
                if prefer == paired[person]:
                    break
                for prefer_of_prefer in preferences[prefer]:
                    if prefer_of_prefer == paired[prefer]:
                        break
                    if prefer_of_prefer == person:
                        is_unhappy = True
                        break
            if is_unhappy:
                ret += 1
        return ret


if __name__ == '__main__':
    sol = Solution()

    n = 4
    preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]]
    pairs = [[0, 1], [2, 3]]
    expected = 2
    assert sol.unhappyFriends(n, preferences, pairs) == expected

    n = 2
    preferences = [[1], [0]]
    pairs = [[1, 0]]
    expected = 0
    assert sol.unhappyFriends(n, preferences, pairs) == expected

    n = 4
    preferences = [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]]
    pairs = [[1, 3], [0, 2]]
    expected = 4
    assert sol.unhappyFriends(n, preferences, pairs) == expected
