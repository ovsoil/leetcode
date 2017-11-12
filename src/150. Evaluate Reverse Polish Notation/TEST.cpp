#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Testcase for Evaluate Reverse Polish Notation", "[]" ) {
    Solution s;
    /*
       ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
       ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
    */

    SECTION("solution 1"){
        vector<string> v;
        v = {"2", "1", "+", "3", "*"};
        REQUIRE( s.evalRPN(v) == 9 );
        v = {"4", "13", "5", "/", "+"};
        REQUIRE( s.evalRPN(v) == 6 );
    }

    SECTION("solution 2"){
        vector<string> v;
        v = {"2", "1", "+", "3", "*"};
        REQUIRE( s.evalRPN2(v) == 9 );
        v = {"4", "13", "5", "/", "+"};
        REQUIRE( s.evalRPN2(v) == 6 );
    }
}
