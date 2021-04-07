class Solution:
    def minFlips(self, target: str) -> int:
        num_flips = 0
        for c in target:
            current_digit = "0" if num_flips % 2 == 0 else "1"
            if current_digit != c:
                num_flips += 1
        return num_flips


if __name__ == '__main__':
    sol = Solution()

    target, expectred = "10111", 3
    assert sol.minFlips(target) == expectred

    target, expectred = "101", 3
    assert sol.minFlips(target) == expectred

    target, expectred = "00000", 0
    assert sol.minFlips(target) == expectred

    target, expectred = "001011101", 5
    assert sol.minFlips(target) == expectred
