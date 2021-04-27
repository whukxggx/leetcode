#pragma once
#include "head.h"

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int rows = grid.size();
		if (rows == 0)return 0;
		int cloumns = grid[0].size();
		vector<vector<int>> vec(rows, vector<int>(cloumns));
		vec[0][0] = grid[0][0];
		for (int i = 1; i < rows; ++i) {
			vec[i][0] = vec[i - 1][0]+grid[i][0];
		}
		for (int i = 1; i < cloumns; ++i) {
			vec[0][i] = vec[0][i - 1]+grid[0][i];
		}
		for (int i = 1; i < rows; ++i) {
			for (int j = 1; j < cloumns; ++j) {
				vec[i][j] = min(vec[i - 1][j], vec[i][j - 1]) + grid[i][j];
			}
		}
		return vec[rows - 1][cloumns - 1];
	}
};