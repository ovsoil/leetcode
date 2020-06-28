#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Jump Game II", "[Greedy][Array]" ) {
    Solution s;

    REQUIRE( s.jump(make_ref(vector<int> {2,3,1,1,4})) == 2 );
    REQUIRE( s.jump(make_ref(vector<int> {0})) == 0 );
}
