#pragma once
#include "head.h"


class Solution {
public:
	//[begin,end)
	int getRes(vector<int> &nums, int begin, int end) {
		int size = end - begin;
		vector<int> dp(end);
		dp[begin] = nums[begin];
		if (size == 1)return dp[begin];
		dp[begin+1] = max(nums[begin], nums[begin + 1]);
		if (size == 2)return dp[begin+1];
		for (int i = begin + 2; i < end; ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}
		return dp[end- 1];
	}
	int rob(vector<int>& nums) {
		int size = nums.size();
		if (size == 0)return 0;
		if (size == 1)return nums[0];
		if (size == 2)return max(nums[0], nums[1]);
		return max(getRes(nums, 0, size - 1), getRes(nums, 1, size));
	}
};