package main

import (
	"fmt"
	"os"
)

func partition(s string) [][]string {
	return backtrack(s, 0)
}

func backtrack(s string, left int) [][]string {
	ret := make([][]string, 0)
	if left >= len(s) {
		return ret
	}
	if isPalindrome(s, left, len(s)-1) {
		ret = append(ret, []string{s[left:]})
	}
	for right := left + 1; right < len(s); right++ {
		if isPalindrome(s, left, right-1) {
			for _, v := range backtrack(s, right) {
				ret = append(ret, append([]string{s[left:right]}, v...))
			}
		}
	}
	return ret
}

func isPalindrome(s string, i int, j int) bool {
	for i < j {
		if s[i] != s[j] {
			return false
		}
		i++
		j--
	}
	return true
}

func equal(v1 [][]string, v2 [][]string) bool {
	if len(v1) != len(v2) {
		return false
	}
	for i := 0; i < len(v1); i++ {
		if len(v1[i]) != len(v2[i]) {
			return false
		}
		for j := 0; j < len(v1[i]); j++ {
			if v1[i][j] != v2[i][j] {
				return false
			}
		}
	}
	return true
}

func main() {
	var s string
	var actual, expected [][]string

	s, expected = "aab", [][]string{{"a", "a", "b"}, {"aa", "b"}}
	actual = partition(s)
	if !equal(actual, expected) {
		fmt.Fprintln(os.Stderr, "s:", s, "actual:", actual, "expected:", expected)
	}

	s, expected = "a", [][]string{{"a"}}
	actual = partition(s)
	if !equal(actual, expected) {
		fmt.Fprintln(os.Stderr, "s:", s, "actual:", actual, "expected:", expected)
	}
}
