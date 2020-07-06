from typing import *


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        ret = [digit for digit in digits]
        if len(ret) == 0:
            return ret
        add_up = 1
        for idx in range(len(digits), 0, -1):
            ret[idx-1] += add_up
            add_up = 0
            if ret[idx-1] != 10:
                break
            ret[idx-1] = 0
            add_up = 1
        if add_up == 1:
            ret.insert(0, add_up)
        return ret


if __name__ == '__main__':
    sol = Solution()

    digits, expected = [1,2,3], [1,2,4]
    assert sol.plusOne(digits) == expected

    digits, expected = [4,3,2,1], [4,3,2,2]
    assert sol.plusOne(digits) == expected

    digits, expected = [1,5,9], [1,6,0]
    assert sol.plusOne(digits) == expected

    digits, expected = [9,9,9], [1,0,0,0]
    assert sol.plusOne(digits) == expected

    digits, expected = [9], [1,0]
    assert sol.plusOne(digits) == expected

    digits, expected = [], []
    assert sol.plusOne(digits) == expected
