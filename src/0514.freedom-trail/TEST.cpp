#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Freedom Trail", "[Depth-first Search][Divide and Conquer][Dynamic Programming]" ) {
    Solution s;

    REQUIRE( s.findRotateSteps(input) == output );
}
