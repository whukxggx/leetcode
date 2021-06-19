#pragma once
#include "head.h"

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int	size1 = s1.size();
		int size2 = s2.size();
		int size3 = s3.size();
		if (size1 + size2 != size3)return false;
		vector<vector<bool>> dp(size1+1, vector<bool>(size2+1));
		dp[0][0] = true;
		for (int i = 0; i <= size1; ++i) {
			for (int j = 0; j <= size2; ++j) {
				if (i > 0) {
					dp[i][j] = dp[i][j]||(dp[i - 1][j] && s1[i-1] == s3[i + j-1]);
				}
				if (j > 0) {
					dp[i][j] = dp[i][j] || (dp[i][j-1] && s2[j - 1] == s3[i + j - 1]);
				}
			}
		}
		return dp[size1][size2];
	}
};