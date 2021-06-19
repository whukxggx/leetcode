#pragma once
#include "head.h"

class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		for (int len = 2; len <= n; ++len) {
			for (int start = 1; start <= n - len + 1; ++start) {
				int res = INT_MAX;
				for (int ite = start; ite < start + len - 1; ++ite) {
					int tmp = ite + max(dp[start][ite - 1], dp[ite + 1][start + len - 1]);
					res = min(tmp, res);
				}
				dp[start][start + len - 1] = res;
			}
		}
		return dp[1][n];
	}
};