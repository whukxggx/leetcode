#pragma once
#include "head.h"

class Solution {
private:
	int memo[30][30][31];//-1 0 1三种取值 0为未计算
	string s1, s2;
public:
	bool isScramble(string s1, string s2) {
		memset(memo, 0, sizeof(memo));
		this->s1 = s1;
		this->s2 = s2;
		return dfs(0, 0, s1.size());
	}
	bool checkScramble(int m, int n, int len) {
		unordered_map<int, int> um;
		for (int i = m; i < m + len; ++i) {
			++um[s1[i]];
		}
		for (int i = n; i < n + len; ++i) {
			--um[s2[i]];
		}
		if (any_of(um.begin(), um.end(), [](const auto& tmp) {return tmp.second != 0; })) {
			return false;
		}
		return true;
	}
	bool dfs(int m, int n, int len) {
		if (memo[m][n][len]) {
			return memo[m][n][len] == 1;
		}
		if (s1.substr(m, len) == s2.substr(n, len)) {
			memo[m][n][len] = 1;
			return true;
		}
		if (!checkScramble(m, n, len)) {
			memo[m][n][len] = -1;
			return false;
		}
		for (int i = 1; i < len; ++i) {
			//不交换
			if (dfs(m, n, i) && dfs(m + i, n + i, len - i)) {
				memo[m][n][len] = 1;
				return true;
			}
			//交换
			if (dfs(m, n+len-i, i) && dfs(m + i, n, len - i)) {
				memo[m][n][len] = 1;
				return true;
			}
		}
		memo[m][n][len] = -1;
		return false;
	}
};