#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"

/*
l1=[0,1], l2=[0,1,2]
l1=[], l2=[0,1]
l1=[9,9], l2=[1]
*/

TEST_CASE( "Testcase for Add Two Numbers", "[number]" ) {
    Solution s;

    REQUIRE( equalList(s.addTwoNumbers(genList({0,1}), genList({0,1,2})), genList({0,2,2})) );
    REQUIRE( equalList(s.addTwoNumbers(genList({}), genList({0,1})), genList({0,1})) );
    REQUIRE( equalList(s.addTwoNumbers(genList({9,9}), genList({1})), genList({0,0,1})) );
}
