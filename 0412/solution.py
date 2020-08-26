from typing import List


class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ret = []
        for i in range(1, n+1):
            if i % 3 == 0 and i % 5 == 0:
                ret.append("FizzBuzz")
            elif i % 5 == 0:
                ret.append("Buzz")
            elif i % 3 == 0:
                ret.append("Fizz")
            else:
                ret.append(str(i))
        return ret


if __name__ == '__main__':
    sol = Solution()

    n = 15
    expected = [
        "1",
        "2",
        "Fizz",
        "4",
        "Buzz",
        "Fizz",
        "7",
        "8",
        "Fizz",
        "Buzz",
        "11",
        "Fizz",
        "13",
        "14",
        "FizzBuzz"
    ]
    assert sol.fizzBuzz(n) == expected
