#pragma once
#include "head.h"

class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int size = nums.size();
		int left = 0, right = 0, minLength = INT_MAX;
		int count = 0;
		while (right < size) {
			count += nums[right];
			++right;
			while(count >= target) {
				minLength = min(minLength, right - left);
				count -= nums[left];
				++left;
			}
		}
		return minLength;
	}
};