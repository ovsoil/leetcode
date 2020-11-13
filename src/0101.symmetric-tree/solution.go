package symmetrictree

import (
	"github.com/ovsoil/leetcode/framework/structures"
)

// TreeNode Use structures.TreeNode
type TreeNode = structures.TreeNode

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
	return relove(root, root)
}

func relove(l *TreeNode, r *TreeNode) bool {
	q := []*TreeNode{l, r}
	for len(q) > 0 {
		u, v := q[0], q[1]
		q = q[2:]
		if u == nil && v == nil {
			continue
		}
		if u == nil || v == nil {
			return false
		}
		if u.Val != v.Val {
			return false
		}
		q = append(q, u.Left)
		q = append(q, v.Right)

		q = append(q, u.Right)
		q = append(q, v.Left)
	}
	return true
}
