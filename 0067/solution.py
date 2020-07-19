from typing import *


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ret = ""
        idx = -1
        carry = 0
        while -idx <= len(a) or -idx <= len(b):
            a_val = int(a[idx]) if -idx <= len(a) else 0
            b_val = int(b[idx]) if -idx <= len(b) else 0
            val = a_val + b_val + carry
            carry = int(val / 2)
            ret = str(val % 2) + ret
            idx -= 1
        if carry == 1:
            ret = str(carry) + ret
        return ret


if __name__ == '__main__':
    sol = Solution()

    a, b = "11", "1"
    expected = "100"
    assert sol.addBinary(a, b) == expected

    a, b = "1010", "1011"
    expected = "10101"
    assert sol.addBinary(a, b) == expected

    a, b = "10101", "1011"
    expected = "100000"
    assert sol.addBinary(a, b) == expected
