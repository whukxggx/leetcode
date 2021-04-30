#pragma once
#include "head.h"


class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int rows = obstacleGrid.size();
		if (rows == 0)return 0;
		int columns = obstacleGrid[0].size();
		vector<vector<int>> vec(rows, vector<int>(columns, 0));
		vec[0][0] = 1;
		if (obstacleGrid[rows - 1][columns - 1] == 1)return 0;
		if (obstacleGrid[0][0] == 1)return 0;
		for (int i = 1; i < rows; ++i) {
			if (obstacleGrid[i][0] != 1) {
				vec[i][0] = vec[i - 1][0];
			}
			else break;
		}
		for (int j = 1; j < columns; ++j) {
			if (obstacleGrid[0][j] != 1) {
				vec[0][j] = vec[0][j - 1];
			}
			else break;;
		}
		for (int i = 1; i < rows; ++i) {
			for (int j = 1; j < columns; ++j) {
				if (obstacleGrid[i][j] == 1)continue;
				vec[i][j] = vec[i - 1][j] + vec[i][j - 1];
			}
		}
		return vec[rows - 1][columns - 1];
	}
};