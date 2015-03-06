#include <string>
#include <algorithm>
#include <iostream>
#include <stdint.h>
using namespace std;

namespace String
{

class Solution
{
public:
    static bool isPalindrome(const string& s)
    {
        string str = s;
        transform(str.begin(), str.end(), str.begin(),  ::tolower);
        auto left = str.begin(), right = prev(str.end());
        while(left < right)
        {
            if(!::isalnum(*left)) ++left;
            else if(!::isalnum(*right)) --right;
            else if(*left != *right) return false;
            else { ++left; --right; }
        }
        return true;
    }


    static char *strStr(char *haystack, const char *needle)
    {
        if(NULL == haystack || NULL == needle)
            return NULL;
        int n1 = strlen(haystack);
        int n2 = strlen(needle);
        if(n1 < n2) return NULL;
        for(int i = 0; i <= n1 - n2; ++i)
        {
            int j = 0;
            while( j < n2 && haystack[i+j] == needle[j])
                ++j;
            if(j == n2)
                return &(haystack[i]);
        }
        return NULL;
    }

    static int atoi(const char *str)
    {
        /* int *p; */
        /* p = new char[strlen(str) + 1]; */
        /* strcpy(p, str); */
        char c;
        while((c = *str) != '\0' && c == ' ') ++str;
        int sign = 1;
        if(*str == '-')
            sign = -1, str++;
        else if(*str == '+')
            sign = 1, str++;
        
        int result = 0;
        while((c = *str++) != '\0')
        {
            if(!::isdigit(c))
                break;
            if(result > INT_MAX / 10)
                return sign == 1 ? INT_MAX : INT_MIN;
            if(sign == 1 && result == INT_MAX / 10 && c - '0' > INT_MAX % 10)
                return INT_MAX;
            if(sign == -1 && result == INT_MAX / 10 && c - '0' > INT_MAX % 10 + 1)
                return INT_MIN;
            result = result * 10 + c - '0';
        }
        return sign * result;
    }
};

}


int main( int argc, char **argv ) {
    using String::Solution;
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
    return 0;
}
