#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums.size() == 3)return nums[0] * nums[1] * nums[2];
		int size = nums.size();
		int bef = nums[0] * nums[1] * nums[2];
		int after = nums[size - 1] * nums[size - 2] * nums[size - 3];
		int another = nums[0] * nums[1] * nums[size - 1];
		return max(bef, max(another, after));
	}
};