class Solution(object):

    number_dict = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z'],
    }

    def product(self, a, b):
        """
        :type a: List[str]
        :type b: List[str]
        :rtype: List[str]
        """
        if len(a) == 0:
            return b
        ret = []
        for a_ele in a:
            ret.extend([a_ele + b_ele for b_ele in b])
        return ret

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        ret = []
        for d in digits:
            ret = self.product(ret, self.number_dict[d])
        return ret


if __name__ == '__main__':
    sol = Solution()
    ans = sol.letterCombinations('23')
    print(ans)
    assert ans == ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
