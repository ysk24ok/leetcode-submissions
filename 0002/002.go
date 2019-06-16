package main

import "fmt"

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	n1 := l1
	n2 := l2
	var leading_node *ListNode
	var last_node *ListNode
	moving_up := 0
	for n1 != nil || n2 != nil {
		v1, v2, sum := 0, 0, 0
		if n1 != nil {
			v1 = n1.Val
			n1 = n1.Next
		}
		if n2 != nil {
			v2 = n2.Val
			n2 = n2.Next
		}
		sum = v1 + v2 + moving_up
		moving_up = sum / 10
		n := &ListNode{Val: sum % 10}
		if leading_node != nil {
			last_node.Next = n
			last_node = n
		} else {
			leading_node = n
			last_node = n
		}
	}
	if moving_up > 0 {
		n := &ListNode{Val: moving_up}
		last_node.Next = n
	}
	return leading_node
}

func main() {
	// l1: 60
	l1 := &ListNode{Val: 0}
	l1.Next = &ListNode{Val: 6}
	// l2: 972
	l2 := &ListNode{Val: 2}
	l2.Next = &ListNode{Val: 7}
	l2.Next.Next = &ListNode{Val: 9}
	got := addTwoNumbers(l1, l2)
	if got.Val != 2 || got.Next.Val != 3 || got.Next.Next.Val != 0 || got.Next.Next.Next.Val != 1 {
		fmt.Printf("%d\n", got.Val)
		fmt.Printf("%d\n", got.Next.Val)
		fmt.Printf("%d\n", got.Next.Next.Val)
		fmt.Printf("%d\n", got.Next.Next.Next.Val)
	}
}
