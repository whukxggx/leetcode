#pragma once
#include "head.h"

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row = triangle.size();
		if (row == 0)return 0;
		vector<vector<int>> dp(row, vector<int>(row, 0));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < row; ++i) {
			dp[i][0] = dp[i - 1][0] + triangle[i][0];
			dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
		}
		for (int i = 1; i < row; ++i) {
			for (int j = 1; j < i; ++j) {
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
		return *min_element(dp[row - 1].begin(), dp[row - 1].end());
	}
};