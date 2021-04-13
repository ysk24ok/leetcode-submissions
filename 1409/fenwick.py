class Fenwick:
    def __init__(self, n):
        sz = 1
        while sz <= n:
            sz *= 2
        self.size = sz
        self.data = [0] * sz

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.data[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i < self.size:
            self.data[i] += x
            i += i & -i

class Solution(object):
    def processQueries(self, queries, n):
        fenw = Fenwick(2 * n)
        vimap = {}
        for i in range(1, n + 1):
            fenw.add(i + n, 1)
            vimap[i] = i + n
            print("key: {}, val: {}".format(i, i+n))
        cur = n
        for i in range(1, 12):
            print(i, fenw.sum(i))

        ans = []
        for q in queries:
            idx = vimap.pop(q)
            rank = fenw.sum(idx-1)
            print("q: {}, idx: {}, rank: {}".format(q, idx, rank))
            ans.append(rank)

            vimap[q] = cur
            print("key: {}, val: {}".format(q, cur))
            fenw.add(idx, -1)
            fenw.add(cur, 1)
            cur -= 1
            for i in range(1, 12):
                print(i, fenw.sum(i))
        return ans


if __name__ == '__main__':
    sol = Solution()
    got = sol.processQueries([3,1,2,1], 5)
    expected = [2,1,2,1]
    assert got == expected
