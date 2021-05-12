#pragma once
#include "head.h"
using namespace std;
class Solution {
public:
	int minDistance(string word1, string word2) {
		int size1 = word1.size();
		int size2 = word2.size();
		if (size1 == 0)return size2;
		if (size2 == 0)return size1;
		vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1,0));
		for (int i = 1; i <= size1; ++i) {
			dp[i][0] = i;
		}
		for (int j = 1; j <= size2; ++j) {
			dp[0][j] = j;
		}
		for (int i = 1; i <= size1; ++i) {
			for (int j = 1; j <= size2; ++j) {
				int res1 = dp[i][j - 1] + 1;
				int res2 = dp[i - 1][j] + 1;
				int res3;
				if (word1[i-1] == word2[j-1])res3 = dp[i - 1][j - 1];
				else res3 = dp[i - 1][j - 1] + 1;
				dp[i][j] = min(min(res1, res2), res3);
			}
		}
		return dp[size1][size2];
	}
};