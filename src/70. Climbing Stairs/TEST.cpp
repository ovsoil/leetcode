#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Testcase for Climbing Stairs", "[leetcode]" ) {
    Solution s;

    REQUIRE( s.climbStairs(2) == 2 );
    REQUIRE( s.climbStairs(3) == 3 );
}
