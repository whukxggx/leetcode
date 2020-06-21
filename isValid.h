#include "head.h"

class Solution
{
public:
    bool isValid(string s)
    {
        int size = s.size();
        if (size == 0)
            return true;
        if (size == 1)
            return false;
        stack<char> sta;
        int i = 0;
        while (i < size)
        {
            switch (s[i])
            {
            case '(':
            case '{':
            case '[':
                sta.push(s[i]);
                break;
            case ')':
                if (sta.top() != '(')
                    return false;
                sta.pop();
                break;
            case '}':
                if (sta.top() != '{')
                    return false;
                sta.pop();
                break;
            case ']':
                if (sta.top() != '[')
                    return false;
                sta.pop();
                break;
            }
            ++i;
        }
        return sta.empty();
    }
};