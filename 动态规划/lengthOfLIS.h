#pragma once
#include "head.h"


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int size = nums.size();
		vector<int> dp(size + 1,INT_MIN/2);
		dp[0] = 0;
		if(size>=1)dp[1] = 1;
		for (int i = 2; i <= size; ++i) {
			dp[i] = max(dp[i], dp[0] + 1);
			for (int j = 1; j < i; ++j) {
				if (nums[i-1] > nums[j-1])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};