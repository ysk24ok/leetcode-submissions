class Solution:
    def minOperations(self, n: int) -> int:
        ret = 0
        target = n
        for idx in range(int(n/2)):
            num = (2 * idx) + 1
            ret += target - num
        return ret


if __name__ == '__main__':
    sol = Solution()

    assert sol.minOperations(3) == 2
    assert sol.minOperations(6) == 9
