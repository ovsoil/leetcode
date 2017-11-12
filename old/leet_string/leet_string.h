#include <cstdint>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

namespace leet_string
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


    /**
     * @brief   Given two binary strings, return their sum (also a binary string). 
     * For example,
     *      a = "11"
     *      b = "1" Return ”100”.
     * @param   a
     * @param   b
     *
     * @return  
     */
    static string addBinary(string a, string b)
    {
        string result;
        size_t n = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for(int i = 0; i < n; ++i)
        {
            int ai = i < a.size() ? a[i] - '0' : 0;
            int bi = i < b.size() ? b[i] - '0' : 0;
            int val = (ai + bi + carry) / 2;
            carry = (ai + bi + carry) % 2;
            result.insert(result.begin(), val + '0');
        }
        if (carry == 1)
            result.insert(result.begin(), '1');
        return result;
    }
    

    /**
     * @brief   Longest Palindromic Substring
     * Given a string S, find the longest palindromic substring in S. 
     * You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
     * 暴力破解
     * @param   s
     *
     * @return  
     */
    static string longestPalindrome( string const& s )
    {
        string result;
        size_t n = s.size();
        int maxlen = 1;
        int begin = 0;
        for(size_t i = 1; i < n-1; ++i)
        {
            int left = i - 1, right = i + 1;    
            int len = 1;
            while(left >= 0 && right < n)
            {
                if(s[left] == s[right])
                {
                    len += 2;
                    --left, ++right;
                }
                else
                {
                    if(len > maxlen)
                    {
                        maxlen = len;
                        begin = left + 1;
                    }
                    break;
                }
            }
        }
        cout << begin << "  " << maxlen << endl;
        result.assign(s.begin() + begin, s.begin() + begin + maxlen);
        return result;
    }

    
    /**
     * @brief   Regular Expression Matching
     * 描述
     * Implement regular expression matching with support for '.' and '*'.
     * '.' Matches any single character. '*' Matches zero or more of the preceding element. 
     * The matching should cover the entire input string (not partial).
     *   Some examples:
     *   isMatch("aa","a") → false
     *   isMatch("aa","aa") → true
     *   isMatch("aaa","aa") → false
     *   isMatch("aa", "a*") → true
     *   isMatch("aa", ".*") → true
     *   isMatch("ab", ".*") → true
     *   isMatch("cab", "c*a*b") → true
     *
     *
     * @param   s
     * @param   p
     *
     * @return  
     */
    static bool isMatch(const char *s, const char *p)
    {
        int i = 0, j = 0;
        int nextchar;
        while(i < strlen(s) && j < strlen(p))
        {
            if(p[i] == s[i] && p[i] != '*' && p[i] != '.')
                ++i, ++j;
            else if(p[i] == '.')
                ++i, ++j;
            else if(p[i] == '*')
            {
                nextchar = p[i+1];
                if()
            }
        }
        
    }

    
    /**
     * @brief   Longest Common Prefix
     * Write a function to find the longest common prefix string amongst an array of strings.
     *
     *
     * @param   strs
     *
     * @return  
     */
    static string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.empty())
            return "";
        for(size_t i = 0; i < strs[0].size(); ++i)
        {
            for(size_t j = 1; j < strs.size(); ++j)
            {
                if( i == strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};

}
