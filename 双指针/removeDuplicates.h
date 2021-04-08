#pragma once
#include "head.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size == 0 || size == 1)return size;
		int first = 0, last = 2;
		while (last < size) {
			if (nums[first] != nums[last]) {
				nums[first + 2] = nums[last];
				++first;
			}
			++last;
		}
		return first + 2;
	}
};