#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Binary Tree Level Order Traversal", "[Tree][Breadth-first Search]" ) {
    Solution s;

    REQUIRE( s.levelOrder(input) == output );
}
