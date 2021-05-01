#pragma once
#include "head.h"


class Solution {
public:
	bool isMatch(string s, string p) {
		int ssize = s.size();
		int psize = p.size();
		vector<vector<bool>> dp(ssize+1, vector<bool>(psize+1, false));
		dp[0][0] = true;
		for (int j = 1; j <= psize; ++j) {
			if (p[j-1] == '*') {
				dp[0][j] = true;
			}
			else
			{
				break;
			}
		}
		for (int i = 1; i <= ssize; ++i) {
			for (int j = 1; j <= psize; ++j) {
				if (p[j - 1] == '*') {
					//使用或者不使用两种选择
					dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
				}
				else {
					if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
						dp[i][j] = dp[i - 1][j - 1];
					}
				}
			}
		}
		return dp[ssize][psize];
	}
};