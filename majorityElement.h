#pragma once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int size = nums.size();
		if (size == 0)return  -1;
		int tmp = nums[0];
		int  count = 1;
		for (int i = 1; i < size; ++i) {
			if (tmp != nums[i]) {
				--count;
			}
			else {
				++count;
			}
			if (count == 0) {
				count = 1;
				tmp = nums[i];
			}
		}
		if (count > 0) {
			int num_count = 0;
			for (int i = 0; i < size; ++i) {
				if (tmp == nums[i])++num_count;
			}
			if (num_count * 2 > size) {
				return tmp;
			}
			else {
				return -1;
			}
		}
		return  -1;
	}
};