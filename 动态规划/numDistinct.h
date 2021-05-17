#pragma once
#include "head.h"


class Solution {
public:
	int numDistinct(string s, string t) {
		int sizes = s.size();
		int sizet = t.size();
		if (sizes <= sizet)return s == t ? 1 : 0;
		vector<vector<long>> dp(sizes+1, vector<long>(sizet+1,0));
		for (int i = 0; i <=sizes; ++i) {
			dp[i][0] = 1;
		}
		for (int j = 1; j <= sizet; ++j) {
			for (int i = j; i <= sizes; ++i) {
				if (s[i - 1] == t[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[sizes][sizet];
	}
};