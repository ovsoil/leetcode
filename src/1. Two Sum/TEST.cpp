#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "TC for Two Sum", "[leetcode]" ) {
    Solution s;
    vector<int> v;

    REQUIRE( s.twoSum({1, 3, 4, 5, 6, 7, 2}, 11) == vector<int>({3, 4}) );
}
