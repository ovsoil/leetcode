#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Add Two Numbers", "[Linked List][Math]" ) {
    Solution s;

    REQUIRE( equalList(s.addTwoNumbers(genList({0,1}), genList({0,1,2})), genList({0,2,2})) );
    REQUIRE( equalList(s.addTwoNumbers(genList({}), genList({0,1})), genList({0,1})) );
    REQUIRE( equalList(s.addTwoNumbers(genList({9,9}), genList({1})), genList({0,0,1})) );
}
