package binarytreelevelordertraversal

import (
	"fmt"
	"github.com/ovsoil/leetcode/framework/structures"
	"reflect"
	"testing"
)

// Binary Tree Level Order Traversal [Tree][Breadth-first Search]
func TestBinaryTreeLevelOrderTraversal(t *testing.T) {

	tcs := []struct {
		input []int   //input
		want  [][]int //output
	}{
		// test case here
		{
			[]int{},
			[][]int{},
		},

		{
			[]int{1},
			[][]int{{1}},
		},

		{
			[]int{3, 9, 20, structures.NULL, structures.NULL, 15, 7},
			[][]int{{3}, {9, 20}, {15, 7}},
		},
	}

	for _, tc := range tcs {

		testname := fmt.Sprintf("%v", tc.input)
		t.Run(testname, func(t *testing.T) {
			root := structures.Ints2TreeNode(tc.input)
			ans := levelOrder(root)
			if !reflect.DeepEqual(ans, tc.want) {
				t.Errorf("got %v, want %v", ans, tc.want)
			}
		})
	}
}
