from typing import List


class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ret = []
        self.recursion(graph, 0, [0], ret)
        return ret

    def recursion(self, graph, node, path: List[int], ret):
        if node == len(graph) - 1:
            ret.append(path)
            return
        for next_node in graph[node]:
            self.recursion(graph, next_node, path + [next_node], ret)


if __name__ == '__main__':
    sol = Solution()

    graph = [[1, 2], [3], [3], []]
    expected = [[0, 1, 3], [0, 2, 3]]
    assert sol.allPathsSourceTarget(graph) == expected
