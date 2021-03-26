#pragma once

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int size = arr.size();
		int res = 0;
		for (int i = 0; i < size; ++i) {
			int leftOdd = (i + 1) / 2;
			int leftEven = i / 2 + 1;
			int rightOdd = (size - i) / 2;
			int rightEven = (size - i - 1) / 2 + 1;
			res += arr[i] * (leftOdd*rightOdd + leftEven * rightEven);
		}
		return  res;
	}
};