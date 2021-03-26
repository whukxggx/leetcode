#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
class Solution {
public:
	inline bool isOdd(int x) {
		return x % 2 == 1;
	}
	bool threeConsecutiveOdds(vector<int>& arr) {
		int  size = arr.size();
		if (size < 3)return false;
		for (int i = 0; i < size - 2; ++i) {
			if (isOdd(arr[i]) && isOdd(arr[i+1]) && isOdd(arr[i+2])) {
				return true;
			}
		}
		return false;
	}
};