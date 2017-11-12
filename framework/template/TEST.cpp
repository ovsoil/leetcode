#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Testcase doc string", "[tag]" ) {
    Solution s;

    REQUIRE( s.function_name(input) == output );
}
