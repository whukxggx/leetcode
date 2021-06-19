#pragma once
#include "head.h"

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty())return 0;
		int size = prices.size();
		k = min(k, size / 2);
		vector<vector<int>> buy(size, vector<int>(k+1));
		vector<vector<int>> sell(size, vector<int>(k+1));
		buy[0][0] = -prices[0];
		sell[0][0] = 0;
		for (int i = 1; i <= k; ++i) {
			buy[0][i] = sell[0][i] = INT_MIN / 2;
		}
		for (int i = 1; i < size; ++i) {
			buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
			for (int j = 1; j <= k; ++j) {
				buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
				sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
			}
		}
		return *max_element(sell[size - 1].begin(), sell[size - 1].end());
	}
};