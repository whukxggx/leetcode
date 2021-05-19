#pragma once
#include "head.h"

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		int minValue = INT_MAX;
		int maxRes = INT_MIN;
		for (int i = 0; i < size; ++i) {
			if (minValue > prices[i]) {
				minValue = prices[i];
			}
			else if(prices[i]-minValue>maxRes){
				maxRes = prices[i] - minValue;
			}
		}
		if (maxRes== INT_MIN)return 0;
		return maxRes;
	}
};