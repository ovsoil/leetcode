#include "StringTest.h"
using leet::Solution;

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( StringTest, "alltest");

void StringTest::setUp()
{
    //for isPalindrome();
    str1 = string("Hello");    
    struct_isPalindrome data1[] = {
        {"yesey", true},
        {"hello", false}
    };
}

void StringTest::tearDown()
{

}

void StringTest::test_isPalindrome()
{
    CPPUNIT_ASSERT(false == Solution::isPalindrome(str1));
}
