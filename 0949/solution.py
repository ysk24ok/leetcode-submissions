from collections import defaultdict
from typing import List


class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        counts = defaultdict(int)
        for val in A:
            counts[val] += 1
        for h1 in reversed(range(3)):
            if h1 not in counts or counts[h1] == 0:
                continue
            counts[h1] -= 1
            max_h2 = 4 if h1 == 2 else 10
            for h2 in reversed(range(max_h2)):
                if h2 not in counts or counts[h2] == 0:
                    continue
                counts[h2] -= 1
                for m1 in reversed(range(6)):
                    if m1 not in counts or counts[m1] == 0:
                        continue
                    counts[m1] -= 1
                    for key, val in counts.items():
                        if val == 1:
                            m2 = key
                            return "{}{}:{}{}".format(h1, h2, m1, m2)
                counts[h2] += 1
            counts[h1] += 1
        return ""


if __name__ == '__main__':
    sol = Solution()

    A = [1, 2, 3, 4]
    expected = "23:41"
    assert sol.largestTimeFromDigits(A) == expected

    A = [5, 5, 5, 5]
    expected = ""
    assert sol.largestTimeFromDigits(A) == expected
