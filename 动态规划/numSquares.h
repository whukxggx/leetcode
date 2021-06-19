#pragma once
#include "head.h"

class Solution {
public:
	int numSquares(int n) {
		int square = sqrt(n);
		vector<int> sqrnum(square + 1,0);
		for (int i = 1; i <= square; ++i) {
			sqrnum[i] = i * i;
		}
		vector<int> dp(n + 1, INT_MAX/2);
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= square; ++j) {
				if (i < sqrnum[j])break;
				else
					dp[i] = min(dp[i], dp[i-sqrnum[j]]+1);
			}
		}
		return dp[n];
	}
};