#include "head.h"

class Solution
{
public:
    int respace(vector<string> &dictionary, string sentence)
    {
        if(sentence.size()==0)return 0;
        int size = sentence.size();
        vector<int> dp(size, INT_MAX);
        unordered_set<string> s;
        for (int i = 0; i < dictionary.size(); ++i)
        {
            s.insert(dictionary[i]);
        }
        if (s.find(sentence.substr(0, 1)) != s.end())
            dp[0] = 0;
        else
            dp[0] = 1;
        for (int i = 1; i < size; ++i)
        {
            dp[i] = i + 1;
            if (s.count(sentence.substr(0, i + 1)))
            {
                dp[i] = 0;
                continue;
            }
            for (int j = i; j > 0; --j)
            {
                if (s.find(sentence.substr(j, i - j + 1)) != s.end())
                {
                    dp[i] = min(dp[i], dp[j - 1]);
                }
                else
                {
                    dp[i] = min(dp[i], dp[j - 1] + i - j + 1);
                }
                if (dp[i] == 0)
                    break;
            }
        }
        return dp[size - 1];
    }
};