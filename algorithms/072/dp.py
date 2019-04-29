"""
  |- h o r s e
--------------
 -|0
 r|  1
 o|    1 2
 s|        2 3
"""


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        old_cost = [i for i in range(len(word1) + 1)]
        for idx2 in range(len(word2)):
            new_cost = [None for i in range(len(word1) + 1)]
            new_cost[0] = old_cost[0] + 1   # delete
            for idx1 in range(len(word1)):
                cost_u = old_cost[idx1+1]
                cost_l = new_cost[idx1]
                cost_ul = old_cost[idx1]
                # identical
                if word2[idx2] == word1[idx1]:
                    new_cost[idx1+1] = cost_ul
                else:
                    # exchange
                    if cost_ul < cost_l and cost_ul < cost_u:
                        new_cost[idx1+1] = cost_ul + 1
                    # insert
                    elif cost_l < cost_u:
                        new_cost[idx1+1] = cost_l + 1
                    # delete
                    else:
                        new_cost[idx1+1] = cost_u + 1
            old_cost = new_cost
        return old_cost[-1]


if __name__ == '__main__':
    sol = Solution()
    w1 = 'horse'
    w2 = 'ros'
    got = sol.minDistance(w1, w2)
    assert got == 3

    w1 = 'intention'
    w2 = 'execution'
    got = sol.minDistance(w1, w2)
    assert got == 5
