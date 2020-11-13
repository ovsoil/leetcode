#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Symmetric Tree", "[Tree][Depth-first Search][Breadth-first Search]" ) {
    Solution s;

    REQUIRE( s.isSymmetric(input) == output );
}
