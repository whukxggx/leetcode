#include"head.h"


class Solution
{
public:
	int countSubstrings(string s)
	{
		int size = s.size();
		vector<vector<bool>> dp(size, vector<bool>(size));
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				dp[i][j] = false;
			}
		}
		int count = 0;
		for (int i = 0; i < size; ++i)
		{
			dp[i][i] = true;
			++count;
		}
		for (int i = 0; i < size - 1; ++i)
		{
			if (s[i] == s[i + 1])
			{
				dp[i][i + 1] = true;
				++count;
			}
		}
		for (int l = 3; l <= size ; ++l)
		{
			for (int i = 0; i < size - l + 1; ++i)
			{
				int j = i + l - 1;
				if (dp[i + 1][j - 1] && s[i] == s[j])
				{
					dp[i][j] = true;
					++count;
				}
			}
		}
		return count;
	}
};
