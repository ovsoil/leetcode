#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Two Sum", "[Array][Hash Table]" ) {
    Solution s;
    REQUIRE( s.twoSum(make_ref(vector<int> {1, 3, 4, 5, 6, 7, 2}), 11) == vector<int>({3, 4}) );
}
