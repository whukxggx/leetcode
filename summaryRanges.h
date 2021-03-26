#pragma once
#include "head.h"
//ÊäÈë£ºnums = [0, 1, 2, 4, 5, 7]
//Êä³ö£º["0->2", "4->5", "7"]
class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int  size = nums.size();
		vector<string> vecStr;
		int i = 0;
		while (i < size) {
			int low = i;
			++i;
			while (i < size&&nums[i] == nums[i - 1] + 1) {
				++i;
			}
			int high = i - 1;
			string tmp = to_string(nums[low]);
			if (low < high) {
				tmp += "->";
				tmp += to_string(nums[high]);
			}
			vecStr.push_back(move(tmp));
		}
		return vecStr;
	}
};