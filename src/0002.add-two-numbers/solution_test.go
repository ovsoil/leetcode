package addtwonumbers

import (
	"fmt"
	"github.com/ovsoil/leetcode/framework/structures"
	"reflect"
	"testing"
)

// Add Two Numbers [Linked List][Math]
func TestAddTwoNumbers(t *testing.T) {

	tcs := []struct {
		l1   []int
		l2   []int
		want []int
	}{
		// test case here
		{
			[]int{},
			[]int{},
			[]int{},
		},

		{
			[]int{1},
			[]int{1},
			[]int{2},
		},

		{
			[]int{1, 2, 3, 4},
			[]int{1, 2, 3, 4},
			[]int{2, 4, 6, 8},
		},

		{
			[]int{1, 2, 3, 4, 5},
			[]int{1, 2, 3, 4, 5},
			[]int{2, 4, 6, 8, 0, 1},
		},

		{
			[]int{1},
			[]int{9, 9, 9, 9, 9},
			[]int{0, 0, 0, 0, 0, 1},
		},

		{
			[]int{9, 9, 9, 9, 9},
			[]int{1},
			[]int{0, 0, 0, 0, 0, 1},
		},

		{
			[]int{2, 4, 3},
			[]int{5, 6, 4},
			[]int{7, 0, 8},
		},

		{
			[]int{1, 8, 3},
			[]int{7, 1},
			[]int{8, 9, 3},
		},
	}

	for _, tc := range tcs {

		testname := fmt.Sprintf("%v,%v", tc.l1, tc.l2)
		t.Run(testname, func(t *testing.T) {
			ans := addTwoNumbers(structures.Ints2List(tc.l1), structures.Ints2List(tc.l2))
			if !reflect.DeepEqual(structures.List2Ints(ans), tc.want) {
				t.Errorf("got %v, want %v", ans, tc.want)
			}
		})
	}
}
