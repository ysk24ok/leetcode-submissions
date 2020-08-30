import math
from collections import defaultdict
from typing import List


def root(parents, idx):
    if parents[idx] == idx:
        return idx
    parent_idx = root(parents, parents[idx])
    parents[idx] = parent_idx
    return parent_idx


def union(parents, idx1, idx2):
    par1 = root(parents, idx1)
    par2 = root(parents, idx2)
    if par1 == par2:
        return
    parents[par1] = par2


class Solution:
    def largestComponentSize(self, A: List[int]) -> int:
        parents = [i for i in range(len(A))]
        common_factors = defaultdict(list)
        for idx, val in enumerate(A):
            for factor1 in range(1, int(math.sqrt(val))+1):
                if val % factor1 != 0:
                    continue
                factor2 = int(val / factor1)
                if factor1 > factor2:
                    break
                elif factor1 == factor2:
                    common_factors[factor1].append(idx)
                else:
                    if factor1 > 1:
                        common_factors[factor1].append(idx)
                    common_factors[factor2].append(idx)
        for factor, L in common_factors.items():
            for idx in range(1, len(L)):
                union(parents, L[0], L[idx])
        ret = 0
        counts = defaultdict(int)
        for idx in range(len(parents)):
            par = root(parents, idx)
            counts[par] += 1
            ret = max(ret, counts[par])
        return ret


if __name__ == '__main__':
    sol = Solution()

    A = [4, 6, 15, 35]
    expected = 4
    assert sol.largestComponentSize(A) == expected

    A = [20, 50, 9, 63]
    expected = 2
    assert sol.largestComponentSize(A) == expected

    A = [2, 3, 6, 7, 4, 12, 21, 39]
    expected = 8
    assert sol.largestComponentSize(A) == expected

    A = [99, 68, 70, 77, 35, 52, 53, 25, 62]
    expected = 8
    assert sol.largestComponentSize(A) == expected
