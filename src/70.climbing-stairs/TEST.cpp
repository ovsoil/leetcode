#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Climbing Stairs", "[Dynamic Programming]" ) {
    Solution s;

    REQUIRE( s.climbStairs(2) == 2 );
    REQUIRE( s.climbStairs(3) == 3 );
}
