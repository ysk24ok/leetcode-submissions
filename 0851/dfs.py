from collections import defaultdict
from typing import *

class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        richers = defaultdict(list)
        for r in richer:
            richers[r[1]].append(r[0])
        answer = [-1 for _ in range(len(quiet))]
        for person in range(len(quiet)):
            self.dfs(person, richers, quiet, answer)
        return answer

    def dfs(self, person: int, richers: Dict[int, List[int]], quiet: List[int], answer: List[int]) -> int:
        if answer[person] != -1:
            return answer[person]
        if person not in richers:
            answer[person] = person
            return person
        loudest = person
        for richer in richers[person]:
            candidate = self.dfs(richer, richers, quiet, answer)
            if quiet[candidate] < quiet[loudest]:
                loudest = candidate
        answer[person] = loudest
        return answer[person]


if __name__ == '__main__':
    sol = Solution()

    richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
    quiet = [3,2,5,4,6,1,7,0]
    expected = [5,5,2,5,4,5,6,7]
    assert sol.loudAndRich(richer, quiet) == expected

    richer = []
    quiet = [0]
    expected = [0]
    assert sol.loudAndRich(richer, quiet) == expected
