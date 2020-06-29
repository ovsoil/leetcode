#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Minimum Size Subarray Sum", "[Array][Two Pointers][Binary Search]" ) {
    Solution s;

    REQUIRE( s.minSubArrayLen(7, make_ref(vector<int>{2,3,1,2,4,3})) == 2 );
}
