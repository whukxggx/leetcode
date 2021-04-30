#pragma once
#include "head.h"

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>>  vec(m, vector<int> (n));
		vec[0][0] = 1;
		for (int i=1; i < m; ++i) {
			vec[i][0] = vec[i - 1][0];
		}
		for (int j = 1; j < n; ++j) {
			vec[0][j] = vec[0][j - 1];
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < m; ++j) {
				vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
			}
		}
		return vec[m - 1][n - 1];
	}
};