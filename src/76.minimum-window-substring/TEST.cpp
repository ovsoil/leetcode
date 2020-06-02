#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Minimum Window Substring", "[Hash Table][Two Pointers][String][Sliding Window]" ) {
    Solution s;

    REQUIRE( s.minWindow("ADOBECODEBANC", "ABC") == "BANC" );
}
