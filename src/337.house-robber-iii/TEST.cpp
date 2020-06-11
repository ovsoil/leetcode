#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "House Robber III", "[Tree][Depth-first Search]" ) {
    Solution s;

    REQUIRE( s.rob(make_binary_tree("[3,2,3,null,3,null,1]")) == 7 );
    REQUIRE( s.rob(make_binary_tree("[3,4,5,1,3,null,1]")) == 9 );
}
