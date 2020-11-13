package binarytreelevelordertraversal

import (
	"github.com/ovsoil/leetcode/framework/structures"
)

// TreeNode use structures.TreeNode
type TreeNode = structures.TreeNode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	ans := [][]int{}
	if root == nil {
		return ans
	}
	q := []*TreeNode{root}
	for len(q) > 0 {
		lv := q
		q = nil
		tmp := []int{}
		for _, node := range lv {
			tmp = append(tmp, node.Val)
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		if len(tmp) > 0 {
			ans = append(ans, tmp)
		}
	}
	return ans
}
