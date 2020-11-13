package twosum

import (
	"fmt"
	"reflect"
	"testing"
	//	"github.com/ovsoil/leetcode/framework/structures"
)

// Two Sum [Array][Hash Table]
func TestTwoSum(t *testing.T) {

	tcs := []struct {
		nums   []int
		target int
		want   []int //output
	}{
		// test case here
		{
			[]int{3, 2, 4},
			6,
			[]int{1, 2},
		},

		{
			[]int{3, 2, 4},
			5,
			[]int{0, 1},
		},

		{
			[]int{0, 8, 7, 3, 3, 4, 2},
			11,
			[]int{1, 3},
		},

		{
			[]int{0, 1},
			1,
			[]int{0, 1},
		},

		{
			[]int{0, 3},
			5,
			nil,
		},
	}

	for _, tc := range tcs {

		testname := fmt.Sprintf("%v,%v", tc.nums, tc.target)
		t.Run(testname, func(t *testing.T) {
			ans := twoSum(tc.nums, tc.target)
			if !reflect.DeepEqual(ans, tc.want) {
				t.Errorf("got %v, want %v", ans, tc.want)
			}
		})
	}
}
