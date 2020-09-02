#include"head.h"

class Solution
{
public:
	//dp[i][j]表示i个0，j个1最多能拼出的字符
	int findMaxForm(vector<string>& strs, int m, int n)
	{
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		for (string s : strs)
		{
			vector<int> count = countZerosOnes(s);
			for (int zeros = m; zeros >= count[0]; --zeros)
			{
				for (int ones = n; ones >= count[1]; --ones)
				{
					dp[zeros][ones] = max(1 + dp[zeros - count[0]][ones - count[1]], dp[zeros][ones]);
				}
			}
		}
		return dp[m][n];
	}
	vector<int> countZerosOnes(string s)
	{
		vector<int> vec(2, 0);
		for (int i = 0; i < s.size(); ++i)
		{
			vec[s[i] - '0']++;
		}
		return vec;
	}
};
