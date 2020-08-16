from typing import List


class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        count = 0
        for num in arr:
            if num % 2 == 1:
                count += 1
            else:
                count = 0
            if count == 3:
                return True
        return False


if __name__ == '__main__':
    sol = Solution()

    arr = [2, 6, 4, 1]
    assert not sol.threeConsecutiveOdds(arr)

    arr = [1, 2, 34, 3, 4, 5, 7, 23, 12]
    assert sol.threeConsecutiveOdds(arr)
