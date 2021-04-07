from leetcode import LinkedList2String, String2LinkedList


def test_String2LinkedList_even():
    s = "1 2 3 4"
    got = String2LinkedList(s)
    assert got.val == 1
    assert got.next.val == 2
    assert got.next.next.val == 3
    assert got.next.next.next.val == 4
    assert got.next.next.next.next is None
    assert LinkedList2String(got) == s


def test_String2LinkedList_odd():
    s = "1 2 3 4 5"
    got = String2LinkedList(s)
    assert got.val == 1
    assert got.next.val == 2
    assert got.next.next.val == 3
    assert got.next.next.next.val == 4
    assert got.next.next.next.next.val == 5
    assert got.next.next.next.next.next is None
    assert LinkedList2String(got) == s


def test_String2LinkedList_empty_string():
    s = ""
    got = String2LinkedList(s)
    assert got is None
    assert LinkedList2String(got) == s
