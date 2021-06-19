#pragma once
#include "head.h"

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())return 0;
		int size = prices.size();
		vector<vector<int>> dp(size, vector<int>(3, 0));
		dp[0][0] = -prices[0];
		for (int i = 1; i < size; ++i) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
			dp[i][1] = dp[i - 1][0] + prices[i];
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
		}
		return max(dp[size - 1][1], dp[size - 1][2]);
	}
};