#pragma once
#include "head.h"

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();
		int pre = nums[0];
		int ans=pre;
		for (int i = 1; i < size; ++i) {
			pre = max(pre+nums[i], nums[i]);
			ans = max(pre, ans);
		}
		return ans;
	}
};