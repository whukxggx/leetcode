#pragma once
#include "head.h"


class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int size = coins.size();
		vector<int> dp(amount + 1,INT_MAX/2);
		dp[0] = 0;
		for (int a = 1; a <= amount; ++a) {
			for (int i =0; i < size; ++i) {
				if (coins[i] <= a) {
					dp[a] = min(dp[a], dp[a - coins[i]] + 1);
				}
			}
		}
		return dp[amount] == INT_MAX/2 ? -1 : dp[amount];
	}
};