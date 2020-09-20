class Solution:
    def reorderSpaces(self, text: str) -> str:
        num_spaces = 0
        for c in text:
            if c == ' ':
                num_spaces += 1
        words = text.split()
        num_intervals = len(words) - 1
        separator = ''
        last_spaces = ' ' * num_spaces
        if num_intervals > 0:
            separator = ' ' * int(num_spaces / num_intervals)
            last_spaces = ' ' * (num_spaces % num_intervals)
        return separator.join(words) + last_spaces


if __name__ == '__main__':
    sol = Solution()

    text = "  this   is  a sentence "
    expected = "this   is   a   sentence"
    assert sol.reorderSpaces(text) == expected

    text = " practice   makes   perfect"
    expected = "practice   makes   perfect "
    assert sol.reorderSpaces(text) == expected

    text = "hello   world"
    expected = "hello   world"
    assert sol.reorderSpaces(text) == expected

    text = "  walks  udp package   into  bar a"
    expected = "walks  udp  package  into  bar  a "
    assert sol.reorderSpaces(text) == expected

    text = "a"
    expected = "a"
    assert sol.reorderSpaces(text) == expected
