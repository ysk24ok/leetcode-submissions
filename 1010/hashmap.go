package main

import (
	"fmt"
	"os"
)

func numPairsDivisibleBy60(time []int) int {
	counts := make(map[int]int)
	ret := 0
	for _, t := range time {
		remainder := t % 60
		v, b := counts[(60-remainder)%60]
		if b {
			ret += v
		}
		counts[remainder] += 1
	}
	return ret
}

func main() {
	var time []int
	var actual, expected int

	time, expected = []int{30, 20, 150, 100, 40}, 3
	actual = numPairsDivisibleBy60(time)
	if actual != expected {
		fmt.Fprintln(os.Stderr, "time:", time, "actual:", actual, "expected:", expected)
	}

	time, expected = []int{60, 60, 60}, 3
	actual = numPairsDivisibleBy60(time)
	if actual != expected {
		fmt.Fprintln(os.Stderr, "time:", time, "actual:", actual, "expected:", expected)
	}
}
