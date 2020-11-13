#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Binary Tree Zigzag Level Order Traversal", "[Stack][Tree][Breadth-first Search]" ) {
    Solution s;

    REQUIRE( s.zigzagLevelOrder(input) == output );
}
