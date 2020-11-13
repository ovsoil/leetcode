package addtwonumbers

import (
	"github.com/ovsoil/leetcode/framework/structures"
)

// ListNode is structures.ListNode
type ListNode = structures.ListNode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var head, tail *ListNode
	carry := 0
	for l1 != nil && l2 != nil {
		sum := l1.Val + l2.Val + carry
		sum, carry = sum%10, sum/10
		if head == nil {
			head = &ListNode{Val: sum}
			tail = head
		} else {
			tail.Next = &ListNode{Val: sum}
			tail = tail.Next
		}
		l1 = l1.Next
		l2 = l2.Next
	}
	l := l1
	if l2 != nil {
		l = l2
	}
	if carry == 0 {
		for l != nil {
			tail.Next = &ListNode{Val: l.Val}
			tail = tail.Next
			l = l.Next
		}
	} else {
		for l != nil {
			sum := l.Val + carry
			sum, carry = sum%10, sum/10
			tail.Next = &ListNode{Val: sum}
			tail = tail.Next
			l = l.Next
		}
	}
	if carry > 0 {
		tail.Next = &ListNode{Val: carry}
	}
	return head
}
