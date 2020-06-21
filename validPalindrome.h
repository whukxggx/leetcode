#include "head.h"

class Solution
{
public:
    bool isVaild(string s)
    {
        int size = s.size();
        int left = 0, right = size - 1;
        while (left < right)
        {
            if (s[left] == s[right])
            {
                ++left;
                --right;
            }else{return false;}
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int size = s.size();
        int left = 0, right = size - 1;
        while (left < right)
        {
            if (s[left] == s[right])
            {
                ++left;
                --right;
            }
            else
            {
                return isVaild(s.substr(left + 1, right - left)) || isVaild(s.substr(left, right - left));
            }
        }
        return true;
    }
};