#pragma once
#include "head.h"

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		//分别是以i结尾的最大和最小的值
		vector<int> fmax(nums), fmin(nums);
		for (int i = 1; i < size; ++i) {
			fmax[i] = max(fmax[i - 1] * nums[i], max(fmin[i - 1] * nums[i], nums[i]));
			fmin[i] = min(fmax[i - 1] * nums[i], min(fmin[i - 1] * nums[i], nums[i]));
		}
		return *max_element(fmax.begin(), fmax.end());
	}
};