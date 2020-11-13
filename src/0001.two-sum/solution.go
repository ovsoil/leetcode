package twosum

// import (
//	"github.com/ovsoil/leetcode/framework/structures"
// )

// // Use structures.TreeNode
// type TreeNode = structures.TreeNode

func twoSum(nums []int, target int) (ans []int) {
	m := make(map[int]int)
	for i, x := range nums {
		if p, ok := m[target-x]; ok {
			return []int{p, i}
		}
		m[x] = i
	}
	return nil
}
