#pragma once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int size = nums.size();
		int mid = 0;
		for (int i = 0; i < size; ++i) {
			mid = i;
			if (nums[i] >= 0)break;
		}
		for (int i = 0; i < size; ++i) {
			nums[i] = nums[i] * nums[i];
		}
		vector<int> vec_ret(size);
		int mid_before = mid - 1;
		int begin = 0;
		while (mid_before >= 0 && mid < size) {
			vec_ret[begin++] = nums[mid_before] < nums[mid] ? nums[mid_before--] : nums[mid++];
		}
		while (mid_before>=0)
		{
			vec_ret[begin++] = nums[mid_before--];
		}
		while (mid<size)
		{
			vec_ret[begin++] = nums[mid++];
		
		}
		return vec_ret;
	}
};