from typing import *


class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        n = len(s)
        neighbors = {i: [] for i in range(n)}
        for i1, i2 in pairs:
            neighbors[i1].append(i2)
            neighbors[i2].append(i1)

        ret = list(s)
        visited = [False for _ in range(n)]
        for index in range(n):
            if visited[index]:
                continue
            indices = []
            self.dfs(index, neighbors, visited, indices)
            chars = [s[index] for index in indices]
            indices.sort()
            chars.sort()
            for idx, char in zip(indices, chars):
                ret[idx] = char
        return ''.join(ret)
   
    # Get all indices of the same group
    def dfs(self, index: int, neighbors: Dict[int, List[int]], visited: List[bool], indices: List[int]) -> None:
        visited[index] = True
        indices.append(index)
        for neighbor in neighbors[index]:
            if visited[neighbor]:
                continue
            self.dfs(neighbor, neighbors, visited, indices)


if __name__ == '__main__':
    sol = Solution()

    s, pairs, expected = "dcab", [[0, 3], [1, 2]], "bacd"
    actual = sol.smallestStringWithSwaps(s, pairs)
    assert actual == expected

    s, pairs, expected = "dcab", [[0, 3], [1, 2], [0, 2]], "abcd"
    actual = sol.smallestStringWithSwaps(s, pairs)
    assert actual == expected

    s, pairs, expected = "cba", [[0, 1], [1, 2]], "abc"
    actual = sol.smallestStringWithSwaps(s, pairs)
    assert actual == expected

    s, pairs, expected = "dcab", [], "dcab"
    actual = sol.smallestStringWithSwaps(s, pairs)
    assert actual == expected
