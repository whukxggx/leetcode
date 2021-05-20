#pragma once
#include "head.h"

class Solution {
private:
	vector<string> vec_str;
public:
	vector<vector<string>> partition(string s) {
		int size = s.size();
		vector<vector<int>> dp(size, vector<int>(size,false));
		for (int i = 0; i < size; ++i) { 
			dp[i][i] = true;
			if (i + 1 < size&&s[i] == s[i + 1])dp[i][i + 1] = true;
		}
		for (int len = 3; len <= size; ++len) {
			for (int i = 0; i < size - len + 1; ++i) {
				int j = i+len-1;
				dp[i][j] = (s[i] == s[j]) ? dp[i + 1][j - 1] : false;
			}
		}
		vector<vector<string>> res;
		dfs(dp, res, s, 0);
		return res;
	}
	void dfs(const vector<vector<int>> &dp, vector<vector<string>> &res,const string &s,int j) {
		int size = s.size();
		if (j == size)res.push_back(vec_str);
		for (int i = j; i < size; ++i) {
			if (dp[j][i]) {
				vec_str.push_back(s.substr(j, i - j + 1));
				dfs(dp, res, s, i + 1);
				vec_str.pop_back();
			}
		}
	}
};
