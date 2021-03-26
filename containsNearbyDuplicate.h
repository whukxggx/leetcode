#pragma once
#include "head.h"

class Solution {
public:
	//³¬Ê±
	//bool containsNearbyDuplicate(vector<int>& nums, int k) {
	//	int size = nums.size();
	//	for (int i = 0; i < size; ++i) {
	//		for (int j = max(i - k, 0); j < i; ++j) {
	//			if (nums[i] == nums[j])return true;
	//		}
	//	}
	//	return false;
	//}
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int size = nums.size();
		unordered_set<int> set_tmp;
		for (int i = 0; i < size; ++i) {
			if (set_tmp.find(nums[i]) != set_tmp.end()) {
				return true;
			}
			set_tmp.insert(nums[i]);
			if (set_tmp.size() > k) {
				set_tmp.erase(nums[i - k]);
			}
		}
		return false;
	}
};