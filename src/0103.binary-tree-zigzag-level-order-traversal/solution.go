package binarytreezigzaglevelordertraversal

import (
	"github.com/ovsoil/leetcode/framework/structures"
)

// Use structures.TreeNode
type TreeNode = structures.TreeNode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
	ans := [][]int{}
	if root == nil {
		return ans
	}
	q := []*TreeNode{root}
	order := true
	for len(q) > 0 {
		tq := q
		n := len(tq)
		q = nil
		lv := []int{}
		if order {
			for i := range tq {
				lv = append(lv, tq[i].Val)
			}
		} else {
			for i := range tq {
				lv = append(lv, tq[n-i-1].Val)
			}
		}
		order = !order
		for _, v := range tq {
			if v.Left != nil {
				q = append(q, v.Left)
			}
			if v.Right != nil {
				q = append(q, v.Right)
			}
		}
		if len(lv) > 0 {
			ans = append(ans, lv)
		}
	}
	return ans
}
