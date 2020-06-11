#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Mini Parser", "[Stack][String]" ) {
    Solution s;

    REQUIRE( s.deserialize(input) == output );
}
