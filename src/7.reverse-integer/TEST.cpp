#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Reverse Integer", "[Math]" ) {
    Solution s;

    REQUIRE( s.reverse(123) == 321 );
    REQUIRE( s.reverse(-123) == -321 );
    REQUIRE( s.reverse(120) == 21 );
    REQUIRE( s.reverse(1234567899) == 0 );
    REQUIRE( s.reverse(2147483647) == 0 );
    REQUIRE( s.reverse(-2147483648) == 0 );
}
