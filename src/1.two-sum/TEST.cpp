#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Two Sum", "[Array][Hash Table]" ) {
    Solution s;
    vector<int> v{1, 3, 4, 5, 6, 7, 2};

    REQUIRE( s.twoSum(v, 11) == vector<int>({3, 4}) );
}
