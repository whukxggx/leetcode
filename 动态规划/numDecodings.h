#pragma once
#include "head.h"

class Solution {
public:
	int numDecodings(string s) {
		int size = s.size();
		vector<int> dp(size+1,0);
		dp[0] = 1;
		for (int i = 1; i <= size; ++i) {
			if (s[i - 1] != '0') {
				dp[i] += dp[i - 1];
			}
			//if (i >=2 &&s[i-2]>'0'&& s[i - 2] <= '2'&&s[i-1] <= '6') {//17 7´óÓÚ6
			if (i >=2 &&s[i-2]>'0'&& ((s[i - 2]-'0')*10+(s[i-1]-'0'))<=26) {
				dp[i] += dp[i - 2];
			}
		}
		return dp[size];
	}
};