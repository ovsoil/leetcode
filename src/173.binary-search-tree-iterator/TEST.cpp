#include "../../framework/header.hpp"
#include "../../framework/common.hpp"
#include "solution.hpp"


TEST_CASE( "Binary Search Tree Iterator", "[Stack][Tree][Design]" ) {

    string input_str = "[7, 3, 15, null, null, 9, 20]";
    TreeNode *btree = gen_binary_tree(input_str);

    BSTIterator *it = new BSTIterator(btree);
    REQUIRE( it->next() == 3 );
    REQUIRE( it->next() == 7 );
    REQUIRE( it->hasNext() == true );
    REQUIRE( it->next() == 9 );
    REQUIRE( it->hasNext() == true );
    REQUIRE( it->next() == 15 );
    REQUIRE( it->hasNext() == true );
    REQUIRE( it->next() == 20 );
    REQUIRE( it->hasNext() == false );
}
