package symmetrictree

import (
	"fmt"
	"github.com/ovsoil/leetcode/framework/structures"
	"reflect"
	"testing"
)

// Binary Tree Level Order Traversal [Tree][Breadth-first Search]
func TestBinaryTreeLevelOrderTraversal(t *testing.T) {

	tcs := []struct {
		input []int //input
		want  bool  //output
	}{
		// test case here
		{
			[]int{3, 4, 4, 5, structures.NULL, structures.NULL, 5, 6, structures.NULL, structures.NULL, 6},
			true,
		},
		{
			[]int{1, 2, 2, structures.NULL, 3, 3},
			true,
		},
		{
			[]int{},
			true,
		},
		{
			[]int{1},
			true,
		},
		{
			[]int{1, 2, 3},
			false,
		},
		{
			[]int{1, 2, 2, 3, 4, 4, 3},
			true,
		},
		{
			[]int{1, 2, 2, structures.NULL, 3, structures.NULL, 3},
			false,
		},
	}

	for _, tc := range tcs {

		testname := fmt.Sprintf("%v", tc.input)
		t.Run(testname, func(t *testing.T) {
			root := structures.Ints2TreeNode(tc.input)
			ans := isSymmetric(root)
			if !reflect.DeepEqual(ans, tc.want) {
				t.Errorf("got %v, want %v", ans, tc.want)
			}
		})
	}
}
