#include"head.h"

class Solution
{
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
	{
		int size = flights.size();
		if (size == 0)return -1;
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = 0; i < n; ++i)dp[i][i] = 0;
		for (int l = 2
	}
};
