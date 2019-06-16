package main

import "fmt"

func firstMissingPositive(nums []int) int {
	// Swap elements in vector so that element at index i should be i+1
	// e.x. if nums[3] is 2, swap nums[3] and nums[2-1]
	idx := 0
	for idx < len(nums) {
		n := nums[idx]
		if n >= 1 && n < len(nums) && n != idx+1 && n != nums[n-1] {
			swap(nums, idx, n-1)
			continue
		}
		idx++
	}
	// When element at index i is not i+1, i+1 is the one
	idx = 0
	for idx < len(nums) && nums[idx] == idx+1 {
		idx++
	}
	return idx+1
}

func swap(nums []int, i int, j int) {
	temp := nums[i]
	nums[i] = nums[j]
	nums[j] = temp
}

func main() {
	var d []int
	var got, expected int
	d = []int{1,2,0}
	got = firstMissingPositive(d)
	expected = 3
	if got != expected {
		fmt.Printf("data: %v, got: %d, expected: %d\n", d, got, expected)
	}
	d = []int{3,2,1}
	got = firstMissingPositive(d)
	expected = 4
	if got != expected {
		fmt.Printf("data: %v, got: %d, expected: %d\n", d, got, expected)
	}
	d = []int{}
	got = firstMissingPositive(d)
	expected = 1
	if got != expected {
		fmt.Printf("data: %v, got: %d, expected: %d\n", d, got, expected)
	}
	d = []int{1, 1}
	got = firstMissingPositive(d)
	expected = 2
	if got != expected {
		fmt.Printf("data: %v, got: %d, expected: %d\n", d, got, expected)
	}
}
