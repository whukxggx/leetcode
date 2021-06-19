#pragma once
#include "head.h"

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if (row == 0)return 0;
		int col = matrix[0].size();
		vector<vector<int>> dp(row, vector<int>(col));
		int maxLen = INT_MIN;
		for (int i = 0; i < row; ++i) {
			dp[i][0] = matrix[i][0]-'0';
			maxLen = max(maxLen, dp[i][0]);
		}
		for (int j = 0; j < col; ++j) {
			dp[0][j] = matrix[0][j]-'0';
			maxLen = max(maxLen, dp[0][j]);
		}
		for (int i = 1; i < row; ++i) {
			for (int j = 1; j < col; ++j) {
				if (matrix[i][j] == '1') {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
					maxLen = max(maxLen, dp[i][j]);
				}
			}
		}
		if (maxLen == INT_MIN)return 0;
		return maxLen*maxLen;
	}
};