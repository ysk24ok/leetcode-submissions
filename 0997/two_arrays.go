package main

import (
	"fmt"
	"os"
)

func findJudge(n int, trust [][]int) int {
	trusted_by := make([]int, n+1)
	trust_others := make([]bool, n+1)
	for i := 0; i < len(trust); i++ {
		trusted_by[trust[i][1]]++
		trust_others[trust[i][0]] = true
	}
	ret := -1
	for i := 1; i <= n; i++ {
		if trusted_by[i] == n-1 && !trust_others[i] {
			ret = i
		}
	}
	return ret
}

func main() {
	var n, actual, expected int
	var trust [][]int

	n, trust = 2, [][]int{{1, 2}}
	actual, expected = findJudge(n, trust), 2
	if actual != expected {
		fmt.Fprintln(os.Stderr, "n:", n, "trust:", trust, "actual:", actual, "expected:", expected)
	}

	n, trust = 3, [][]int{{1, 3}, {2, 3}}
	actual, expected = findJudge(n, trust), 3
	if actual != expected {
		fmt.Fprintln(os.Stderr, "n:", n, "trust:", trust, "actual:", actual, "expected:", expected)
	}

	n, trust = 3, [][]int{{1, 3}, {2, 3}, {3, 1}}
	actual, expected = findJudge(n, trust), -1
	if actual != expected {
		fmt.Fprintln(os.Stderr, "n:", n, "trust:", trust, "actual:", actual, "expected:", expected)
	}

	n, trust = 3, [][]int{{1, 2}, {2, 3}}
	actual, expected = findJudge(n, trust), -1
	if actual != expected {
		fmt.Fprintln(os.Stderr, "n:", n, "trust:", trust, "actual:", actual, "expected:", expected)
	}
}
