#include"head.h"

class Solution
{
public:
	int maxTurbulenceSize(vector<int>& A)
	{
		int size = A.size();
		if (size == 0)return 0;
		if (size == 1)return 1;
		vector<int> dp(size);
		dp[0] = 1;
		dp[1] = (A[0] != A[1]) ? 2 : 1;
		int maxlen = dp[1];
		for (int i = 2; i < size; ++i)
		{
			if ((A[i] > A[i - 1] && A[i - 1] < A[i - 2]) || (A[i] < A[i - 1] && A[i - 1] > A[i - 2]))
			{
				dp[i] = max(dp[i - 1] + 1, 3);
				if (dp[i] > maxlen)maxlen = dp[i];
			}
			else
			{
				dp[i] = 1;
			}
		}
		return maxlen;
	}
};
