"""
Let S be a given word and W be a word contained in `words` variable.
When the number of characters in a group in S is
    1, the number in W must be 1
    2, the number in W must be 2
    3, the number in W can be 1,2,3
    4, the number in W can be 1,2,3,4
    5, ...
"""

class Solution:
    def breakDownString(self, s):
        """
        :param s: a string (e.x. "heeellooo")
        :type s: str
        :returns: length of each character in a given string
                  (e.x. [('h', 1), ('e', 3), ('l', 2), ('o', 3)])
        :rtype: List[(str, int)]
        """
        prev_c = None
        count = 0
        l = []
        for c in s:
            if prev_c is not None and c != prev_c:
                l.append((prev_c, count))
                count = 0
            count += 1
            prev_c = c
        l.append((prev_c, count))
        return l

    def expressiveWords(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        l_S = self.breakDownString(S)
        count = 0
        for W in words:
            l_W = self.breakDownString(W)
            ok = True
            if len(l_S) != len(l_W):
                continue
            for pair_S, pair_W in zip(l_S, l_W):
                if pair_S[0] != pair_W[0]:
                    ok = False
                    break
                if pair_S[1] == 1 and pair_W[1] != 1:
                    ok = False
                    break
                if pair_S[1] == 2 and pair_W[1] != 2:
                    ok = False
                    break
                if pair_S[1] >= 3 and pair_W[1] > pair_S[1]:
                    ok = False
                    break
            if ok is True:
                count += 1
        return count


if __name__ == '__main__':
    sol = Solution()
    S = "heeellooo"
    words = ["hello", "hi", "helo", "heello", "heeello"]
    got = sol.expressiveWords(S, words)
    assert got == 3     # hello, heello, heeello
    words = ['heko']
    got = sol.expressiveWords(S, words)
    assert got == 0
