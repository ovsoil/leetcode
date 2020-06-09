#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Exclusive Time of Functions", "[Stack]" ) {
    Solution s;
    REQUIRE( s.exclusiveTime(2, make_ref(vector<string> {"0:start:0", "1:start:2", "1:end:5", "0:end:6"})) == vector<int>{3, 4} );
}
