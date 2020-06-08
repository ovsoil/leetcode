#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Symmetric Tree", "[Tree][Depth-first Search][Breadth-first Search]" ) {
    Solution s;

    REQUIRE( s.isSymmetric(make_binary_tree("[1,2,2,3,4,4,3]")) == true );
    REQUIRE( s.isSymmetric(make_binary_tree("[1,2,2,null,3,null,3]")) == false );
}
