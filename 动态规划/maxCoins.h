#pragma once
#include "head.h"


class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int size = nums.size();
		vector<vector<int>> dp(size+2, vector<int>(size+2,0));
		vector<int> val(size + 2);
		val[0] = val[size + 1] = 1;
		for (int i = 1; i <= size; ++i) {
			val[i] = nums[i - 1];
		}
		for (int i = size - 1; i >= 0; --i) {
			for (int j = i + 2; j <= size + 1; ++j) {
				for (int k = i + 1; k < j; ++k) {
					int sum = val[i] * val[k] * val[j];
					sum += dp[i][k] + dp[k][j];
					dp[i][j] = max(dp[i][j], sum);
				}
			}
		}
		return dp[0][size + 1];
	}
};