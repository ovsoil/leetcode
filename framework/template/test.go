package PACKAGENAME

import (
	"fmt"
	"reflect"
	"testing"
	//	"github.com/ovsoil/leetcode/framework/structures"
)

// Testcase doc string [tag]
func TestTESTNAME(t *testing.T) {

	tcs := []struct {
		input int //input
		want  int //output
	}{
		// test case here
	}

	for _, tc := range tcs {

		testname := fmt.Sprintf("%v", tc.input)
		t.Run(testname, func(t *testing.T) {
			ans := FUNCNAME(tc.input)
			if !reflect.DeepEqual(ans, tc.want) {
				t.Errorf("got %v, want %v", ans, tc.want)
			}
		})
	}
}
