package freedomtrail

import (
	"fmt"
	"reflect"
	"testing"
	// "github.com/ovsoil/leetcode/framework/structures"
)

// Freedom Trail [Depth-first Search][Divide and Conquer][Dynamic Programming]
func TestFreedomTrail(t *testing.T) {

	tcs := []struct {
		ring string //input
		key  string
		want int //output
	}{
		// test case here
		{
			"godding",
			"gd",
			4,
		},
	}

	for _, tc := range tcs {

		testname := fmt.Sprintf("%v,%v", tc.ring, tc.key)
		t.Run(testname, func(t *testing.T) {
			ans := findRotateSteps(tc.ring, tc.key)
			if !reflect.DeepEqual(ans, tc.want) {
				t.Errorf("got %v, want %v", ans, tc.want)
			}
		})
	}
}
