#pragma once
#include "head.h"

class Solution {
public:
	int longestValidParentheses(string s) {
		int size = s.size();
		if (size == 0)return 0;
		vector<int> dp(size, 0);
		dp[0] = 0;
		int maxLen = 0;
		for (int i = 1; i < size; ++i) {
			if (s[i] == ')') {
				if (s[i - 1] == '(')dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
				else if (s[i-1] ==')') {
					if ((i-dp[i-1]>=1)&&s[i - dp[i - 1] - 1] == '(')
						dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0);
				}
			}
			maxLen = max(dp[i], maxLen);
		}
		return maxLen;
	}
};