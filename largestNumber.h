#pragma once
#include "head.h"

class Solution {
	static bool compare(int x, int y) {
		long tx = 10, ty = 10;
		while (tx <= x) tx *= 10;
		while (ty <= y) ty *= 10;
		return x * ty + y > y*tx + x;
	}
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), compare);
		if (nums[0] == 0)return "0";
		string ans = "";
		for (int i : nums) {
			ans += to_string(i);
		}
		return ans;
	}
};

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [](const int &x,const int &y) {
			long tx = 10, ty = 10;
			while (tx <= x) tx *= 10;
			while (ty <= y) ty *= 10;
			return x * ty + y > y*tx + x;
			});
		if (nums[0] == 0)return "0";
		string ans = "";
		for (int i : nums) {
			ans += to_string(i);
		}
		return ans;
	}
};
