from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        max_dist = 2 ** 31 - 1
        d = [max_dist for _ in range(N+1)]
        d[K] = 0
        while True:
            has_update = False
            for start_node, end_node, dist in times:
                if d[start_node] == max_dist:
                    continue
                new_dist = d[start_node] + dist
                if new_dist < d[end_node]:
                    has_update = True
                    d[end_node] = new_dist
            if has_update is False:
                break
        ret = 0
        for idx in range(1, N+1):
            dist = d[idx]
            if dist == max_dist:
                return -1
            ret = max(ret, dist)
        return ret


if __name__ == '__main__':
    sol = Solution()

    times, N, K = [[2, 1, 1], [2, 3, 1], [3, 4, 1]], 4, 2
    expected = 2
    assert sol.networkDelayTime(times, N, K) == expected
