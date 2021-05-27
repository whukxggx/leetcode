#pragma once
#include "head.h"

class Solution {
public:
	int nthUglyNumber(int n) {
		int pow2 =1;
		int pow3 = 1;
		int pow5 = 1;
		vector<int> dp(n + 1);
		dp[1] = 1;
		for(int i=2;i<=n;++i){
			dp[i] = min(2*dp[pow2], min(3*dp[pow3], 5*dp[pow5]));
			if (dp[i] == 2 * dp[pow2])++pow2;
			if (dp[i] == 3 * dp[pow3])++pow3;
			if (dp[i] == 5 * dp[pow5])++pow5;
		}
		return dp[n];
	}
};