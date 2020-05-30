#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Implement strStr()", "[Two Pointers][String]" ) {
    Solution s;

    SECTION("solution 01"){
        REQUIRE( s.strStr("", "") == 0 );
        REQUIRE( s.strStr("hello", "ll") == 2 );
        REQUIRE( s.strStr("aaaaa", "bba") == -1 );
        REQUIRE( s.strStr("mississippi", "issi") == 1 );
        REQUIRE( s.strStr("mississippi", "issipi") == -1 );
    };

    SECTION("solution 01"){
        REQUIRE( s.strStr2("", "") == 0 );
        REQUIRE( s.strStr2("hello", "ll") == 2 );
        REQUIRE( s.strStr2("aaaaa", "bba") == -1 );
        REQUIRE( s.strStr2("mississippi", "issi") == 1 );
        REQUIRE( s.strStr2("mississippi", "issipi") == -1 );
    };
}
