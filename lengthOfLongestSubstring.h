#include "head.h"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxSize = 0;
        int size = s.size();
        string st;
        int pos;
        for (int i = 0; i < size; ++i)
        {
            if ((pos = st.find(s[i])) == string::npos)
                st.push_back(s[i]);
            else
            {
                maxSize = max(maxSize, (int)st.size());
                st = st.substr(pos + 1);
                --i;
            }
        }
        maxSize = max(maxSize, (int)st.size());
        return maxSize;
    }
};