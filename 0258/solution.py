class Solution:
    def addDigits(self, num: int) -> int:
        while num >= 10:
            num = self.newDigits(num)
        return num

    def newDigits(self, num: int) -> int:
        new_num = 0
        while num > 0:
            new_num += num % 10
            num = int(num / 10)
        return new_num


if __name__ == '__main__':
    sol = Solution()

    num, expected = 38, 2
    assert sol.addDigits(num) == expected
