#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "House Robber II", "[Dynamic Programming]" ) {
    Solution s;

    REQUIRE( s.rob(make_ref(vector<int> {1})) == 1 );
    REQUIRE( s.rob(make_ref(vector<int> {2,3,2})) == 3 );
    REQUIRE( s.rob(make_ref(vector<int> {1,2,3,1})) == 4 );
}
