#pragma once
#include "head.h"

class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		vector<int> dp(size);
		dp[0] = nums[0];
		if (size == 1)return dp[0];
		dp[1] = max(nums[0], nums[1]);
		if (size == 2)return dp[1];
		for (int i = 2; i < size; ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp[size - 1];
	}
};