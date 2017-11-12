#include "leet_string.h"

int main( int argc, char **argv ) {
    using leet::Solution;
    cout << Solution::isPalindrome("sdbeeb") << endl;
    cout << Solution::isPalindrome("A man, a plan, a canal: Panama") << endl;

    char s[] = "sdafyuuewoqhg";
    char *p = Solution::strStr( s,  "yuu");
    cout << p << endl;

    cout << "-11" << Solution::atoi("-11") << endl;
    cout << " +2147483646: " << Solution::atoi(" +2147483646") << endl;
    cout << " +2147483647: " << Solution::atoi(" +2147483647") << endl;
    cout << " +2147483648: " << Solution::atoi(" +2147483648") << endl;
    cout << " +2147483649: " << Solution::atoi(" +2147483649") << endl;
    cout << "-2147483647: " << Solution::atoi("-2147483647") << endl;
    cout << "-2147483648: " << Solution::atoi("-2147483648") << endl;
    cout << "-2147483649: " << Solution::atoi("-2147483649") << endl;
    cout << "-2147483659: " << Solution::atoi("-2147483659") << endl;
    cout << "-214748365900: " << Solution::atoi(" -214748365900") << endl;
    cout << "-11111111111111111874900: " << Solution::atoi("-11111111111111111874900") << endl;
    cout << "INT_MAX:" << INT_MAX << endl;
    cout << "INT_MIN:" << INT_MIN << endl;
    
    cout << Solution::longestPalindrome( "hellsoadfkfdasfasg") << endl;
    return 0;
}
