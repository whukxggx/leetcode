#pragma once
#include "head.h"

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int size = nums.size();
		sort(nums.begin(), nums.end());
		vector<int> dp(size, 1);
		int maxLen = 1;
		int maxVal = dp[0];
		for (int i = 1; i < size; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] % nums[j] == 0) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			if (dp[i] > maxLen) {
				maxLen = dp[i];
				maxVal = nums[i];
			}
		}
		if (maxLen == 1)return { nums[0] };
		vector<int> res;
		for (int i = size - 1; i >= 0 && maxLen > 0; --i) {
			if (dp[i] == maxLen && maxVal%nums[i] == 0) {
				res.push_back(nums[i]);
				--maxLen;
				maxVal = nums[i];
			}
		}
		return res;
	}
};