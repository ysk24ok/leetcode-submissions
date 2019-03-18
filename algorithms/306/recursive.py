class Solution:

    def isAdditiveNumber(self, num: str) -> bool:
        """Search the first pair of additive numbers
        e.x. When 'num' is 124816, try
            1 + 2, 1 + 24, 1 + 248, ...
            12 + 4, 12 + 48, ...
            124 + 8, ...
        """
        start_idx = 0
        for first_len in range(1, len(num)):
            first = num[0:first_len]
            if first_len >= 2 and first[0] == '0':
                continue
            for second_len in range(1, len(num)):
                second_idx = first_len + second_len
                second = num[first_len:second_idx]
                if second_len >= 2 and second[0] == '0':
                    continue
                expected_third = str(int(first) + int(second))
                expected_third_len = len(expected_third)
                third_idx = second_idx + expected_third_len
                actual_third = num[second_idx:third_idx]
                if actual_third != expected_third:
                    continue
                if third_idx == len(num):
                    return True
                if self.check(num, first_len, second, expected_third):
                    return True
        return False

    def check(self, num: str, start_idx: int, first: str, second: str):
        """Given the first pair of additive numbers,
        check recursively whether the input number is additive
        e.x. When 'num' is 112368 and (first, second) is (1, 1), try
            1 + 1 = 2
            1 + 2 = 3
            2 + 3 = 5 != 6  -> return False
        """
        third = str(int(first) + int(second))
        first_len = len(first)
        second_len = len(second)
        third_start_idx = start_idx + first_len + second_len
        third_end_idx = third_start_idx + len(third)
        if num[third_start_idx:third_end_idx] == third:
            if third_end_idx == len(num):
                return True
            return self.check(num, start_idx + first_len, second, third)
        return False


if __name__ == '__main__':
    sol = Solution()
    # 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
    s = '112358'
    assert sol.isAdditiveNumber(s) is True
    # 1 + 99 = 100, 99 + 100 = 101
    s = '199100199'
    assert sol.isAdditiveNumber(s) is True
    # 1 + 0 = 1
    s = '101'
    assert sol.isAdditiveNumber(s) is True
    # 13 + 2 = 15
    s = '13215'
    assert sol.isAdditiveNumber(s) is True
    # try 1 + 0, 1 + 00, 10 + 0, 100 + 1, 1001 + 1, ...
    s = '100110'
    assert sol.isAdditiveNumber(s) is False
    # try 0 + 2, 0 + 23, 0 + 235, 02 + 3, ...
    s = '0235813'
    assert sol.isAdditiveNumber(s) is False
    # 12 + 12 = 24, 12 + 24 = 36
    s = '12122436'
    assert sol.isAdditiveNumber(s) is True
    # 12 + 0 = 12, 0 + 12 = 12, 12 + 12 = 24, 12 + 24 = 36
    s = '12012122436'
    assert sol.isAdditiveNumber(s) is True
