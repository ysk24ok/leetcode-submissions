from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        memo = [None for _ in range(len(s))]
        return self.recursive(s, 0, wordDict, memo)

    def recursive(self, s, idx, wordDict, memo):
        if idx == len(s):
            return [""]
        if memo[idx] is not None:
            return memo[idx]
        ret = []
        for word in wordDict:
            if not self.starts_with(s, idx, word):
                continue
            for word_used in self.recursive(s, idx+len(word), wordDict, memo):
                if word_used == "":
                    ret.append(word)
                else:
                    ret.append(word + " " + word_used)
        memo[idx] = ret
        return ret

    def starts_with(self, s, idx, word):
        ret = True
        for c in word:
            if idx >= len(s) or s[idx] != c:
                ret = False
                break
            idx += 1
        return ret


if __name__ == '__main__':
    sol = Solution()

    s = "catsanddog"
    wordDict = ["cat", "cats", "and", "sand", "dog"]
    expected = ["cat sand dog", "cats and dog"]
    assert sol.wordBreak(s, wordDict) == expected

    s = "pineapplepenapple"
    wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
    expected = [
        "pine apple pen apple",
        "pine applepen apple",
        "pineapple pen apple",
    ]
    assert sol.wordBreak(s, wordDict) == expected
