// main.cpp

// 不用再包含所有TestFixture子类的头文件
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
// 如果不更改TestSuite, 本文件后期不需要更改. 
int main()
{
    CppUnit::TextUi::TestRunner runner;
    
    // 从注册的TestSuite中获取特定的TestSuite, 没有参数获取未命名的TestSuite.
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry("alltest");
    // 添加这个TestSuite到TestRunner中
    runner.addTest( registry.makeTest() );
    // 运行测试
    runner.run();
}
