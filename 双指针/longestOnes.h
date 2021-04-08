#pragma once
#include "head.h"


class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int size = A.size();
		int left = 0, right = 0,countZeros=0;
		int maxCount = 0;
		while (right < size) {
			if (A[right] == 0) ++countZeros;
			++right;
			if(countZeros > K) {
				if (A[left] == 0)--countZeros;
				++left;
			}
			maxCount = max(maxCount, right - left);
		}
		return maxCount;
	}
};


class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int size = A.size();
		int left = 0, right = 0, lsum = 0, rsum = 0,maxCount=0;
		while (right < size) {
			rsum += 1 - A[right];
			++right;
			while (lsum < rsum - K) {
				lsum += 1 - A[left];
				++left;
			}
			maxCount = max(maxCount, right - left);
		}
		return maxCount;
	}
};