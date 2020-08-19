vowels = ('a', 'i', 'u', 'e', 'o')


class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split()
        ret = [None for _ in range(len(words))]
        for idx, word in enumerate(words):
            if word[0].lower() in vowels:
                ret[idx] = word + "ma"
            else:
                ret[idx] = word[1:] + word[0] + "ma"
            ret[idx] += "a" * (idx + 1)
        return " ".join(ret)


if __name__ == '__main__':
    sol = Solution()

    S = "I speak Goat Latin"
    expected = "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
    assert sol.toGoatLatin(S) == expected

    S = "The quick brown fox jumped over the lazy dog"
    expected = ("heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa"
                " overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa")
    assert sol.toGoatLatin(S) == expected
