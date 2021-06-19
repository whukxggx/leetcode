#pragma once
#include "head.h"


class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> dp(n + 1);
		int highBits = 0;
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			if ((i&(i - 1)) == 0) {//注意运算符优先级
				highBits = i;
			}
			dp[i] = dp[i - highBits] + 1;
		}
		return dp;
	}
};