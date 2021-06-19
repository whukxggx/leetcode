#pragma once
#include "head.h"

class Solution {
public:
	int minCut(string s) {
		int size = s.size();
		vector<vector<int>> dp(size, vector<int>(size, false));
		for (int i = 0; i < size; ++i) {
			dp[i][i] = true;
			if (i + 1 < size&&s[i] == s[i + 1])dp[i][i + 1] = true;
		}
		for (int len = 3; len <= size; ++len) {
			for (int i = 0; i < size - len + 1; ++i) {
				int j = i + len - 1;
				dp[i][j] = (s[i] == s[j]) ? dp[i + 1][j - 1] : false;
			}
		}
		vector<int> vec(size, INT_MAX);
		for (int i = 0; i < size; ++i) {
			if (dp[0][i])vec[i] = 0;
			else {
				for (int j = 0; j < i; ++j) {
					if(dp[j+1][i])
					vec[i] = min(vec[i], vec[j] + 1);
				}
			}
		}
		return vec[size - 1];
	}
};