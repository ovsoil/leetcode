#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Intersection of Two Arrays II", "[Sort][Hash Table][Two Pointers][Binary Search]" ) {
    Solution s;
    
    vector<int> nums1 = vector<int>{1, 2, 2, 1};
    vector<int> nums2 = vector<int>{2, 2};
    REQUIRE( s.intersect(nums1, nums2) == vector<int>{2, 2} );
}
