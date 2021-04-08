#pragma once
#include "head.h"

class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		int size = nums.size();
		int left = 0, right = 0, countZeros = 0;
		int maxCount = 0;
		while (right < size) {
			if (nums[right] == 0) ++countZeros;
			++right;
			if (countZeros > 1) {
				if (nums[left] == 0)--countZeros;
				++left;
			}
			maxCount = max(maxCount, right - left);
		}
		return maxCount-1;
	}
};