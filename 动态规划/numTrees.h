#pragma once
#include "head.h"



///超出时间限制
class Solution {
public:
	int back(int begin, int end) {
		if (begin > end||begin==end)return 1;
		int res=0;
		for (int i = begin; i <= end; ++i) {
			int leftNum = back(begin, i - 1);
			int rightNum = back(i + 1, end);
			int num = leftNum * rightNum;
			res += num;
		}
		return res;
	}
	int numTrees(int n) {
		return back(1, n);
	}
};


class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n + 1,0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				dp[i] = dp[j] * dp[i - j-1];//左边从零个到i-1个
			}
		}
		return dp[n];
	}
};