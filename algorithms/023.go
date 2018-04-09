package main

import "fmt"

type PriorityQueue struct {
	elements []int
}

func (q *PriorityQueue) push(element int) {
	q.elements = append(q.elements, element)
	current_idx := len(q.elements) - 1
	parent_idx := (current_idx - 1) / 2
	for q.elements[current_idx] < q.elements[parent_idx] {
		q.swap(current_idx, parent_idx)
		current_idx = parent_idx
		parent_idx = (current_idx - 1) / 2
	}
}

func (q *PriorityQueue) pop() (int, bool) {
	length := len(q.elements)
	var element int
	if length == 0 {
		return element, false
	}
	element = q.elements[0]
	q.elements[0] = q.elements[length-1]
	q.elements = q.elements[:length-1]
	length = len(q.elements)
	current_idx := 0
	for {
		left_child_idx := current_idx * 2 + 1
		right_child_idx := current_idx * 2 + 2
		// no child nodes
		if left_child_idx >= length {
			break
		}
		cv := q.elements[current_idx]
		lv := q.elements[left_child_idx]
		// only left child node exists
		if left_child_idx == length - 1 {
			if cv > lv {
				q.swap(current_idx, left_child_idx)
			}
			break
		}
		// both child nodes exist
		rv := q.elements[right_child_idx]
		if cv <= lv && cv <= rv {
			break
		}
		if lv < rv {
			q.swap(current_idx, left_child_idx)
			current_idx = left_child_idx
		} else {
			q.swap(current_idx, right_child_idx)
			current_idx = right_child_idx
		}
	}
	return element, true
}

func (q *PriorityQueue) swap(i int, j int) {
	tmp := q.elements[i]
	q.elements[i] = q.elements[j]
	q.elements[j] = tmp
}

/**
 * Definition for singly-linked list.
 */
type ListNode struct {
	Val int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {
	q := &PriorityQueue{}
	for _, n := range lists {
		for n != nil {
			q.push(n.Val)
			n = n.Next
		}
	}
	head := &ListNode{0, nil}
	last := head
	for {
		v, exists := q.pop()
		if exists == false {
			break
		}
		last.Next = &ListNode{v, nil}
		last = last.Next
	}
	return head.Next
}


func main() {
	// l1: 6 8
	// l2: 3 3
	// l3: 10
	l1 := &ListNode{6, nil}
	l1.Next = &ListNode{8, nil}
	l2 := &ListNode{3, nil}
	l2.Next = &ListNode{3, nil}
	l3 := &ListNode{10, nil}
	v1 := []*ListNode{l1, l2, l3}
	got1 := mergeKLists(v1)
	var expected int
	expected = 3
	if got1.Val != expected {
		fmt.Println("got:", got1.Val, ", expected:", expected)
	}
	expected = 3
	if got1.Next.Val != expected {
		fmt.Println("got:", got1.Next.Val, ", expected:", expected)
	}
	expected = 6
	if got1.Next.Next.Val != expected {
		fmt.Println("got:", got1.Next.Next.Val, ", expected:", expected)
	}
	expected = 8
	if got1.Next.Next.Next.Val != expected {
		fmt.Println("got:", got1.Next.Next.Next.Val, ", expected:", expected)
	}
	expected = 10
	if got1.Next.Next.Next.Next.Val != expected {
		fmt.Println("got:", got1.Next.Next.Next.Next.Val, ", expected:", expected)
	}

	// empty slice
	var v2 []*ListNode
	got2 := mergeKLists(v2)
	if got2 != nil {
		fmt.Println("got:", got2, ", expected:", nil)
	}
}
