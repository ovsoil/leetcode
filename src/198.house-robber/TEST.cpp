#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "House Robber", "[Dynamic Programming]" ) {
    Solution s;

    REQUIRE( s.rob(make_ref(vector<int> {1,2,3,1})) == 4 );
    REQUIRE( s.rob(make_ref(vector<int> {2,7,9,3,1})) == 12 );
}
