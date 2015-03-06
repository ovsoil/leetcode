#ifndef _STRINGTEST_H
#define _STRINGTEST_H
#include "cppunit/extensions/HelperMacros.h"
#include "../leet_string/leet_string.h"

class StringTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE( StringTest );
    CPPUNIT_TEST(test_isPalindrome);
    CPPUNIT_TEST_SUITE_END();

public:
    StringTest(){}
    void setUp();
    void tearDown();

    void test_isPalindrome();
protected:
    //测试数据
    //for isPalindrome()
    string str1;
    struct struct_isPalindrome
    {
        const string str;
        bool result;
    };
    struct_isPalindrome *data1;
};

#endif /* STRINGTEST_H */
